﻿using UnityEngine;
using System;
using System.Collections.Generic;

namespace Tapdaq {

	public class TDSettings : ScriptableObject {
		private static TDSettings instance;

		public const string pluginVersion = "unity_7.10.0";
		
		public string ios_applicationID = "";
		public string ios_clientKey = "";
		public string android_applicationID = "";
		public string android_clientKey = "";

        public string admob_appid_ios = "";
        public string admob_appid_android = "";

        public bool isDebugMode = false;
		public bool autoReloadAds = false;

		[SerializeField]
		public List<TDNetwork> networks = new List<TDNetwork>(TDNetwork.AllNetworks.ToArray());

		[SerializeField]
		public List<TestDevice> testDevices = new List<TestDevice>();

		[SerializeField]
		public List<TDKeyValuePair> skAdNetworkIds = new List<TDKeyValuePair>();

		public static TDSettings getInstance()
		{
			if (instance == null)
			{
				TDSettings[] settings = Resources.LoadAll<TDSettings>("Tapdaq");
				if (settings != null && settings.Length > 0)
				{
					instance = settings[0];
					instance.clean();
				}
				else
				{
					return new TDSettings();
				}
			}
			return instance;
		}

		private void clean()
		{
			if (this.networks.Count == 0)
			{
				Debug.Log("Networks Empty, repopulating");
				this.networks = new List<TDNetwork>(TDNetwork.AllNetworks.ToArray());
			}

			List<TDNetwork> tmp = new List<TDNetwork>(this.networks);
			foreach (TDNetwork network in tmp)
			{
				if (String.IsNullOrEmpty(network.name))
				{
					Debug.Log("Network name missing, removing");
					this.networks.Remove(network);
				}
			}
		}
	}


	public enum TestDeviceType {
		Android,
		iOS
	}

	[Serializable]
	public class TestDevice {

		public string name;
		public TestDeviceType type;

		public string adMobId;
		public string facebookId;

		public TestDevice(string deviceName, TestDeviceType deviceType) {
			name = deviceName;
			type = deviceType;
		}
	}

	[Serializable]
	public class TestDevicesList {
	
		[SerializeField]
		public List<string> adMobDevices = new List<string>();
		[SerializeField]
		public List<string> facebookDevices = new List<string>();

		public TestDevicesList(List<TestDevice> devices, TestDeviceType deviceType) {

			foreach (var device in devices) {
				if (device.type == deviceType) {
					if (!string.IsNullOrEmpty (device.adMobId)) {
						adMobDevices.Add (device.adMobId);
					}
					if (!string.IsNullOrEmpty (device.facebookId)) {
						facebookDevices.Add (device.facebookId);
					}
				}
			}
		}

		public override string ToString ()
		{
			return JsonUtility.ToJson(this);
		}

		public string GetAdMobListJson() {
			return JsonUtility.ToJson(adMobDevices);
		}

		public string GetFacebookListJson() {
			return JsonUtility.ToJson(facebookDevices);
		}
	}

	[Serializable]
	public class TDKeyValuePair
	{
		[SerializeField]
		private string key;
		[SerializeField]
		private string value;

		public TDKeyValuePair(string key, string value)
		{
			this.key = key;
			this.value = value;
		}

		public string getKey() { return key; }
		public string getValue() { return value; }
	}
}