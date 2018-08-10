using System.IO;
using UnityEngine;
using UnityEditor;
using UnityEditor.Callbacks;
using System.Text.RegularExpressions;
using System;
using System.Collections;
using Tapdaq;


using TDEditor.iOS.Xcode;


public class TapdaqBuildPostprocessor : MonoBehaviour{
	private static string FrameworksPath = "Frameworks/Plugins/";
	private static string FrameworksDir = "iOS";
	private static string ResourcesPath = "/Plugins/iOS/";
	private const string BuildPathKey = "IOSBuildProjectPath";

	[MenuItem ("Tapdaq/Run iOS Build Postprocess", false, 2222)]
	private static void RunIOSPostProcessManually()	{
		var path = EditorPrefs.GetString (BuildPathKey, null);
		OnPostprocessBuild (BuildTarget.iOS, path);
	}

	[MenuItem ("Tapdaq/Run iOS Build Postprocess", true)]
	static bool validateRunPostBuilder(){
		var path = EditorPrefs.GetString (BuildPathKey, null);
		if( path == null || !Directory.Exists( path ) )
			return false;

		var projectFile = Path.Combine( path, "Unity-iPhone.xcodeproj/project.pbxproj" );
		if( !File.Exists( projectFile ) )
			return false;

		return true;
	}

	private static void processExistingiOSPaths (string targetPath)  {
		foreach (string dirPath in Directory.GetDirectories(targetPath + "/" + FrameworksPath)) {
			var dirName = Path.GetFileName(dirPath);
			if (String.Compare(dirName, "ios", true) == 0) {
				
				FrameworksDir = dirName;
			}
		}
	}
	

	[PostProcessBuild(101)]
    public static void OnPostprocessBuild(BuildTarget buildTarget, string pathToBuiltProject) {
		if (buildTarget != BuildTarget.iOS) return;
		
		EditorPrefs.SetString (BuildPathKey, pathToBuiltProject);

            var path = PBXProject.GetPBXProjectPath(pathToBuiltProject);
            if (!File.Exists(path)) {
                TDDebugLogger.LogError(string.Format("pbxproj '{0}' does not exists", path));
                return;
            }

	        var proj = new PBXProject();
	        proj.ReadFromString(File.ReadAllText(path));
	        var target = proj.TargetGuidByName("Unity-iPhone");


			processExistingiOSPaths(pathToBuiltProject);
			SetBuildProperties(proj, target);

            AddLibraries(proj, target, pathToBuiltProject);

			SetPListProperties(pathToBuiltProject);

            File.WriteAllText(path, proj.WriteToString());

			RenameMRAIDSource (pathToBuiltProject);

	}

	private static void RenameMRAIDSource (string buildPath) {
		// Unity will try to compile anything with the ".js" extension. Since mraid.js is not intended
		// for Unity, it'd break the build. So we store the file with a masked extension and after the
		// build rename it to the correct one.

        string[] maskedFiles = Directory.GetFiles (buildPath, "*.prevent_unity_compilation", SearchOption.AllDirectories);


		foreach (string maskedFile in maskedFiles) {
            string unmaskedFile = maskedFile.Replace (".prevent_unity_compilation", ".js");
			File.Move(maskedFile, unmaskedFile);
		}
	}

	private static void SetBuildProperties(PBXProject proj, string target) {
		proj.SetBuildProperty(target, "ENABLE_BITCODE", "YES");
		proj.SetBuildProperty(target, "LD_RUNPATH_SEARCH_PATHS", "$(inherited) @executable_path/Frameworks");
		proj.SetBuildProperty(target, "IPHONEOS_DEPLOYMENT_TARGET", GetIOSDeploymentTarget(proj));
        proj.SetBuildProperty(target, "CLANG_ENABLE_MODULES", "YES");
        proj.UpdateBuildProperty(target, "OTHER_LDFLAGS", new string [] { "-ObjC" }, new string [] {});



        proj.AddFrameworkToProject(target, "MessageUI.framework", false);
        proj.AddFrameworkToProject(target, "AdSupport.framework", false);
        proj.AddFrameworkToProject(target, "CoreData.framework", false);
        proj.AddFrameworkToProject(target, "SystemConfiguration.framework", false);
        proj.AddFrameworkToProject(target, "EventKit.framework", false);
        proj.AddFrameworkToProject(target, "EventKitUI.framework", false);
        proj.AddFrameworkToProject(target, "WatchConnectivity.framework", false);
        proj.AddFrameworkToProject(target, "libz.dylib", false);
        proj.AddFrameworkToProject(target, "libsqlite3.tbd", false);
        proj.AddFrameworkToProject(target, "libc++.tbd", false);
        proj.AddFrameworkToProject(target, "libxml2.tbd", false);


        if (AssetDatabase.FindAssets ("YouAppiAdapter.framework").Length > 0) {
			proj.SetBuildProperty (target, "ALWAYS_EMBED_SWIFT_STANDARD_LIBRARIES", "YES");
			proj.SetBuildProperty (target, "DEFINES_MODULE", "YES");
		}
	}

	private static void AddLibraries(PBXProject proj, string target, string projectPath) {
		foreach(var name in Enum.GetNames(typeof(TapdaqAdapter))) {
			if (name.Equals("YouAppiAdapter")) {
                proj.EmbedFramework (target, FrameworksPath + FrameworksDir +"/Tapdaq/Network-SDKs/YouAppiAdapter/YouAppiMoat.framework");
			}
		}

		if (AssetDatabase.FindAssets ("Tapjoy.framework").Length > 0) {
			if (!proj.ContainsFileByProjectPath ("TapjoyResources.bundle")) {
                var fullPath = FrameworksPath + FrameworksDir 
                    + "/Tapdaq/Network-SDKs/TapjoyAdapter/Tapjoy.framework/Resources/TapjoyResources.bundle";
				proj.AddFileToBuild (target, proj.AddFile (fullPath, "TapjoyResources.bundle", PBXSourceTree.Source));
			}
		}

        if (AssetDatabase.FindAssets ("MoPubSDKFramework.framework").Length > 0) {
			if (!proj.ContainsFileByProjectPath ("MoPub.bundle")) {
                var fullPathMoPub = FrameworksPath + FrameworksDir + "/Tapdaq/Network-SDKs/MoPubAdapter/MoPub.bundle";
                proj.AddFileToBuild (target, proj.AddFile (fullPathMoPub, "MoPub.bundle", PBXSourceTree.Source));
			}
		}

        if (AssetDatabase.FindAssets ("PlayableAds.framework").Length > 0) {
			if (!proj.ContainsFileByProjectPath ("ZplayMuteListener.bundle")) {
                var fullPath = FrameworksPath + FrameworksDir + "/Tapdaq/Network-SDKs/ZPlayAdapter/PlayableAds.framework/Resources/ZplayMuteListener.bundle";
				proj.AddFileToBuild (target, proj.AddFile (fullPath, "ZplayMuteListener.bundle", PBXSourceTree.Source));
			}
		}
	}

	private static void SetPListProperties(string pathToBuiltProject) {
		
		var plistPath = pathToBuiltProject + "/Info.plist";
		var plist = new PlistDocument();

		plist.ReadFromString(File.ReadAllText(plistPath));
		var rootDict = plist.root;

		if(AssetDatabase.FindAssets("AdColonyAdapter.framework").Length > 0) {
			rootDict.SetString("NSMotionUsageDescription", "Interactive ad controls");
			rootDict.SetString("NSPhotoLibraryUsageDescription", "Taking selfies");
			rootDict.SetString("NSCalendarsUsageDescription", "Adding events");
		}

		var transportSecurityKey = "NSAppTransportSecurity";

		if (rootDict [transportSecurityKey] == null) {
			rootDict.CreateDict (transportSecurityKey);
		}

		var appTransportSecurity = rootDict [transportSecurityKey].AsDict ();
		
		appTransportSecurity.SetBoolean ("NSAllowsArbitraryLoads", true);

		if(AssetDatabase.FindAssets("AdMobAdapter.framework").Length > 0) {
			//appTransportSecurity.SetBoolean("NSAllowsArbitraryLoadsForMedia", true);
			//appTransportSecurity.SetBoolean("NSAllowsArbitraryLoadsInWebContent", true);
		}

		// Write to file
		File.WriteAllText(plistPath, plist.WriteToString());
	}

	private static string GetIOSDeploymentTarget(PBXProject proj) {
		var target = proj.TargetGuidByName("Unity-iPhone");
		var deploymentTargets = proj.GetBuildProperties (target, "IPHONEOS_DEPLOYMENT_TARGET");

		var deploymentTarget = "0";
		if (deploymentTargets.Count > 0) {
			deploymentTarget = deploymentTargets [0];
		}

		if (string.IsNullOrEmpty (deploymentTarget))
			deploymentTarget = "0";

		Regex rgx = new Regex("[^0-9.]");
		var numberOnly = rgx.Replace(deploymentTarget, "");

		var version = Tapdaq.TDExtensionMethods.ParseFloat (numberOnly, 0);

		if (version >= 8.0f)
			return deploymentTarget;

		TDDebugLogger.LogWarning ("TapdaqBuildPostprocessor changes iOS build target version from " + deploymentTarget + " to = 8.0");

		return "8.0";
	}
}
