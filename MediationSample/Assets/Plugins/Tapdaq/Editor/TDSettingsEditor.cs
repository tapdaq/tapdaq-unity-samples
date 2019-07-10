using UnityEngine;
using UnityEditor;
using System;
using System.Collections.Generic;
using Tapdaq;

namespace TDEditor {
	[CustomEditor (typeof(TDSettings))]
    public class TDSettingsEditor : UnityEditor.Editor
    {
		private TDSettings settings;

		private bool showOther = false;

		private bool showTestDevices = false;

		private GUIStyle foldoutStyle;

		private List<TestDevice> deviceToDelete = new List<TestDevice>();

		private Texture whiteTexture;

		void OnEnable () {
			whiteTexture = Texture2D.whiteTexture;
			settings = (TDSettings)target;
			TDManifestResolver.FixAndroidManifest ();
		}

		public override void OnInspectorGUI () {
			foldoutStyle = EditorStyles.foldout;
			foldoutStyle.fontStyle = FontStyle.Bold;

			serializedObject.Update ();

			GUILayout.Label ("You must have an App ID and Client Key to use Tapdaq", EditorStyles.boldLabel);
		
			if (GUILayout.Button ("Visit Tapdaq.com")) {
				Application.OpenURL ("https://tapdaq.com/dashboard/apps");
			}

			GUILayout.Label ("Current version:", EditorStyles.boldLabel);
			GUILayout.Label ("Unity plugin: \t" + TDSettings.pluginVersion);

			GUILayout.Space(15);
		
			GUILayout.Label ("App Settings", EditorStyles.boldLabel);
		
			settings.ios_applicationID = EditorGUILayout.TextField ("iOS Application ID", settings.ios_applicationID);
			settings.ios_clientKey = EditorGUILayout.TextField ("iOS Client Key", settings.ios_clientKey);

            GUILayout.Space(15);

            settings.admob_appid_ios = EditorGUILayout.TextField("AdMob AppId (iOS)", settings.admob_appid_ios);

			GUILayout.Space(20);

			settings.android_applicationID = EditorGUILayout.TextField ("Android Application ID", settings.android_applicationID);
			settings.android_clientKey = EditorGUILayout.TextField ("Android Client Key", settings.android_clientKey);

			GUILayout.Space (15);

			settings.autoReloadAds = EditorGUILayout.Toggle("Auto-reload Ads", settings.autoReloadAds);

			GUILayout.Space (15);

			settings.isDebugMode = EditorGUILayout.Toggle("Debug Mode?", settings.isDebugMode);

			GUILayout.Space (14);

			ShowTestDevices ();

			if (GUI.changed)
				EditorUtility.SetDirty (settings);
		}

		private void ShowTestDevices() {

			showTestDevices = EditorGUILayout.Foldout (showTestDevices, "Test devices", foldoutStyle);

			deviceToDelete.Clear ();

			if (showTestDevices) {
				foreach (var device in settings.testDevices) {
					ShowTestDevice (device);
				}

				ShowAddTestDeviceView ();
			}

			foreach (var device in deviceToDelete) {
				settings.testDevices.Remove (device);
			}
		}

		string newTestDeviceName = "";
		TestDeviceType newTestDeviceType = TestDeviceType.Android;

		private void ShowAddTestDeviceView() {
			
			GUIStyle labelStyle = new GUIStyle(EditorStyles.boldLabel);

			GUILayout.Label ("Add new device.", labelStyle);

			newTestDeviceName = EditorGUILayout.TextField ("Name:", newTestDeviceName);
			newTestDeviceType = (TestDeviceType)EditorGUILayout.EnumPopup ("Type:", newTestDeviceType);

			ShowButton ("Add", 90, Color.green, () => {
				if (!string.IsNullOrEmpty (newTestDeviceName)) {
					var testDevice = new TestDevice (newTestDeviceName, newTestDeviceType);
					settings.testDevices.Add (testDevice);
					newTestDeviceName = "";
				}
			});

			DrawSeparator (2);
		}

		private void ShowDeleteDialog(TestDevice device) {
			if (EditorUtility.DisplayDialog ("Delete Test Device", 
				"Are you sure you want to delete test device " + device.name + "?", 
				"Delete", "Cancel")) {

				deviceToDelete.Add (device);
			}
		}

		private void ShowTestDevice(TestDevice device) {

			GUIStyle labelStyle = new GUIStyle(EditorStyles.boldLabel);
			var isAndroid = device.type == TestDeviceType.Android;
			labelStyle.normal.textColor = isAndroid ? new Color (0, 0.3f, 0) : new Color (0, 0, 0.3f);

			GUILayout.Label (device.name + " (" + device.type.ToString () + ")", labelStyle);

			device.adMobId = EditorGUILayout.TextField ("AdMob ID:", device.adMobId);
			device.facebookId = EditorGUILayout.TextField ("Facebook ID:", device.facebookId);

			ShowButton ("Delete", 50, new Color (0.85f, 0.15f, 0), () => {
				ShowDeleteDialog (device);
			});

			DrawSeparator (2);
		}

		private void DrawSeparator(int height) {
			GUILayout.Box (whiteTexture, GUILayout.ExpandWidth (true), GUILayout.Height (height));
		}

		private void ShowButton(string text, int width, Color color, Action action) {
			GUI.backgroundColor = color;
			if (GUILayout.Button (text, GUILayout.Width (width))) {
				if (action != null)
					action.Invoke ();
			}
			GUI.backgroundColor = Color.white;
		}
	}
}