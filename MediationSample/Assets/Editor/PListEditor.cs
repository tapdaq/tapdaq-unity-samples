using UnityEngine;
using UnityEditor;
using UnityEditor.Callbacks;
using UnityEditor.iOS.Xcode;
using System.IO;
 
public class PListEditor : MonoBehaviour
{

    [PostProcessBuild(102)]
    public static void ChangeXcodePlist(BuildTarget buildTarget, string pathToBuiltProject)
    {

        if (buildTarget == BuildTarget.iOS)
        {

            // Get plist
            string plistPath = pathToBuiltProject + "/Info.plist";
            PlistDocument plist = new PlistDocument();
            plist.ReadFromString(File.ReadAllText(plistPath));

            // Get root
            PlistElementDict rootDict = plist.root;

            rootDict.SetString("NSUserTrackingUsageDescription", "Please let me use IDFA");

            // Write to file
            File.WriteAllText(plistPath, plist.WriteToString());
        }
    }
}