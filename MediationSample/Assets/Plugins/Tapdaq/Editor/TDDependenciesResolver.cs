// <copyright file="GPGSDependencies.cs" company="Google Inc.">
// Copyright (C) 2015 Google Inc. All Rights Reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License");
//  you may not use this file except in compliance with the License.
//  You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
//  Unless required by applicable law or agreed to in writing, software
//  distributed under the License is distributed on an "AS IS" BASIS,
//  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//  See the License for the specific language governing permissions and
//    limitations under the License.
// </copyright>

using System;
using System.Collections.Generic;
using UnityEditor;

[InitializeOnLoad]
public class TDDependencies : AssetPostprocessor {
	#if UNITY_ANDROID
	public static object svcSupport;

	// This value may be set as low as 11.0.0+ ****
	private static string minimumPlayServicesVersion = "15.0.0+"; 
	

	// DO NOT CHANGE THESE VALUES 
	private static string minimumVunglePlayServicesVersion = "11.0.4+";

	private static string minimumSupportLibraryVersion = "24.0.0+";
	private static string minimumInMobiSupportLibraryVersion = "24.0.0+";
	private static string minimumFANSupportLibraryVersion = "24.0.0+";
	private static string minimumVungleSupportLibraryVersion = "26.0.0+";
	#endif

	static TDDependencies() {
		RegisterDependencies();
	}
		
	public static void RegisterDependencies() {
		#if UNITY_ANDROID
		RegisterAndroidDependencies();
		#elif UNITY_IOS
		RegisterIOSDependencies();
		#endif
	}

	// Compares two version numbers. Must have at least 2 numbers e.g. 1.0
	// Plus symbols will be removed for comparison but return value will include them
	private static string getHighestVersion(string v, string v1) {
		var version1 = new Version(v.Replace("+",""));
		var version2 = new Version(v1.Replace("+",""));
		
		var result = version1.CompareTo(version2);
		if (result > 0)
			return v;
		else if (result < 0)
			return v1;
	
		return v;
	}

	#if UNITY_ANDROID
	private static bool IsPlayServicesVersion15orHigher() {
		string majorVersionString = minimumPlayServicesVersion.Substring(0, minimumPlayServicesVersion.IndexOf("."));
		int majorVersionInteger = int.Parse (majorVersionString);
		return majorVersionInteger >= 15;
	}

	public static void RegisterAndroidDependencies() {
		// Setup the resolver using reflection as the module may not be
		// available at compile time.
		Type playServicesSupport = Google.VersionHandler.FindClass(
			"Google.JarResolver", "Google.JarResolver.PlayServicesSupport");
		if (playServicesSupport == null) {
			return;
		}

		svcSupport = svcSupport ?? Google.VersionHandler.InvokeStaticMethod(
			playServicesSupport, "CreateInstance",
			new object[] {
				"GooglePlayGames",
				EditorPrefs.GetString("AndroidSdkRoot"),
				"ProjectSettings"
			});

		string playServicesVersion = minimumPlayServicesVersion;
		string supportLibraryVersion = minimumSupportLibraryVersion;

		if (AssetDatabase.FindAssets ("TapdaqInMobiAdapter").Length > 0) {
			supportLibraryVersion = getHighestVersion(supportLibraryVersion, minimumInMobiSupportLibraryVersion);
		}
		if (AssetDatabase.FindAssets ("TapdaqFANAdapter").Length > 0) {
			supportLibraryVersion = getHighestVersion(supportLibraryVersion, minimumFANSupportLibraryVersion);
		}
		if (AssetDatabase.FindAssets ("TapdaqVungleAdapter").Length > 0) {
			playServicesVersion = getHighestVersion(playServicesVersion, minimumVunglePlayServicesVersion);
			supportLibraryVersion = getHighestVersion(supportLibraryVersion, minimumVungleSupportLibraryVersion);
		}

		//Required by Tapdaq
		if(IsPlayServicesVersion15orHigher()) {
			Google.VersionHandler.InvokeInstanceMethod(
				svcSupport, "DependOn",
				new object[] { "com.google.android.gms", "play-services-ads-identifier", playServicesVersion },
			namedArgs: new Dictionary<string, object>() {
				{"packageIds", new string[] { "extra-google-m2repository" } }
			});
		} else {
			Google.VersionHandler.InvokeInstanceMethod(
			svcSupport, "DependOn",
				new object[] { "com.google.android.gms", "play-services-basement", playServicesVersion },
			namedArgs: new Dictionary<string, object>() {
				{"packageIds", new string[] { "extra-google-m2repository" } }
			});
		}

		Google.VersionHandler.InvokeInstanceMethod(
			svcSupport, "DependOn",
			new object[] { "com.android.support", "support-v4", supportLibraryVersion },
		namedArgs: new Dictionary<string, object>() {
			{"packageIds", new string[] { "extra-android-m2repository" } }
		});

		//Required by AdMob
		if (AssetDatabase.FindAssets ("TapdaqAdMobAdapter").Length > 0) {
			Google.VersionHandler.InvokeInstanceMethod (
				svcSupport, "DependOn",
				new object[] { "com.google.android.gms", "play-services-ads", playServicesVersion },
				namedArgs: new Dictionary<string, object> () {
					{ "packageIds", new string[] { "extra-google-m2repository" } }
				});
		
			Google.VersionHandler.InvokeInstanceMethod (
				svcSupport, "DependOn",
				new object[] { "com.google.android.gms", "play-services-ads-lite", playServicesVersion },
				namedArgs: new Dictionary<string, object> () {
					{ "packageIds", new string[] { "extra-google-m2repository" } }
				});

			Google.VersionHandler.InvokeInstanceMethod (
				svcSupport, "DependOn",
				new object[] { "com.google.android.gms", "play-services-base", playServicesVersion },
				namedArgs: new Dictionary<string, object> () {
					{ "packageIds", new string[] { "extra-google-m2repository" } }
				});
		}
			
		//Required by InMobi
		if(AssetDatabase.FindAssets("TapdaqInMobiAdapter").Length > 0) {
			Google.VersionHandler.InvokeInstanceMethod(
				svcSupport, "DependOn",
				new object[] { "com.android.support", "recyclerview-v7", supportLibraryVersion },
				namedArgs: new Dictionary<string, object>() {
				{"packageIds", new string[] { "extra-android-m2repository" } }
			});
		}

		//Required by FAN
		if(AssetDatabase.FindAssets("TapdaqFANAdapter").Length > 0) {
			Google.VersionHandler.InvokeInstanceMethod(
				svcSupport, "DependOn",
				new object[] { "com.android.support", "recyclerview-v7", supportLibraryVersion },
			namedArgs: new Dictionary<string, object>() {
				{"packageIds", new string[] { "extra-android-m2repository" } }
			});
		}

		if (AssetDatabase.FindAssets ("TapdaqVungleAdapter").Length > 0) {
			Google.VersionHandler.InvokeInstanceMethod (
				svcSupport, "DependOn",
				new object[] { "com.google.android.gms", "play-services-gcm", playServicesVersion },
			namedArgs: new Dictionary<string, object> () {
				{ "packageIds", new string[] { "extra-google-m2repository" } }
			});
		}
	}
	#endif

	public static void RegisterIOSDependencies() {
	}

	// Handle delayed loading of the dependency resolvers.
	private static void OnPostprocessAllAssets(
		string[] importedAssets, string[] deletedAssets,
		string[] movedAssets, string[] movedFromPath) {
		foreach (string asset in importedAssets) {
			if (asset.Contains("IOSResolver") ||
				asset.Contains("JarResolver")) {
				RegisterDependencies();
				break;
			}
		}
	}
}

