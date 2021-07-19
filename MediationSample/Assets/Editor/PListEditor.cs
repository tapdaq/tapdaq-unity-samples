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
            addSKAdNetworkIDs(rootDict);

            // Write to file
            File.WriteAllText(plistPath, plist.WriteToString());
        }
    }

    private static void addSKAdNetworkIDs(PlistElementDict rootDict)
    {
        PlistElementArray skAdNetworkItemsArray = rootDict.CreateArray("SKAdNetworkItems");

        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "22mmun2rn5.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "238da6jt44.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "2u9pt9hc89.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "3rd42ekr43.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "3sh42y64q3.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "424m5254lk.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "4468km3ulz.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "44jx6755aq.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "44n7hlldy6.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "488r3q3dtq.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "4dzt52r2t5.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "4fzdc2evr5.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "4pfyvq9l8r.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "578prtvx9j.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "5a6flpkh64.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "5l3tpt7t6e.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "5lm9lj6jb7.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "737z793b9f.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "7rz58n8ntl.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "7ug5zh24hu.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "8s468mfl3y.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "9rd848q2bz.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "9t245vhmpl.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "av6w8kgt66.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "bvpn9ufa9b.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "c6k4g5qg8m.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "cg4yq2srnc.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "cj5566h2ga.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "cstr6suwn9.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "ecpz2srf59.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "ejvt5qm6ak.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "f38h382jlk.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "f73kdq92p3.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "ggvn48r87g.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "glqzh8vgby.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "gta9lk7p23.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "hs6bdukanm.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "kbd757ywx3.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "klf5c3l5u5.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "lr83yxwka7.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "ludvb6z3bs.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "m8dbw4sv7c.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "mlmmfzh3r3.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "mtkv5xtk9e.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "n38lu8286q.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "n9x2a789qt.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "ppxm28t8ap.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "prcb7njmu6.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "su67r6k2v3.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "t38b2kh725.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "tl55sbb4fm.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "uw77j35x4d.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "v4nxqhlyqp.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "v72qych5uu.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "v79kvwwj4g.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "v9wttpbfk9.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "w9q455wk68.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "wg4vff78zm.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "wzmmz9fp6w.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "yclnxrl5pm.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "ydx93a7ass.skadnetwork");
        skAdNetworkItemsArray.AddDict().SetString("SKAdNetworkIdentifier", "zmvfpc5aq8.skadnetwork");
    }
}