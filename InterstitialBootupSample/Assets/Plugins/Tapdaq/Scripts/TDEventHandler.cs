﻿using UnityEngine;

namespace Tapdaq {
	public class TDEventHandler : MonoBehaviour {
		private static TDEventHandler reference;

		public static TDEventHandler instance {
			get {
				if (!reference) {
					TDEventHandler[] references = FindObjectsOfType<TDEventHandler> ();

					if (references.Length > 0) {
						reference = references [0]; 
					} else {
						reference = new GameObject ("TapdaqV1").AddComponent<TDEventHandler> ();
						TDDebugLogger.Log (":: Ad test ::" + "Spawned Event Handler");
					}
				}

				return reference;
			}
		}

		private void Awake () {
			DontDestroyOnLoad (gameObject);
		}

		// Currently just used as an empty call to make a TDEventHandler GameObject
		public void Init () {

		}

		void _didLoadConfig(string message) {
			TDDebugLogger.LogWarning ("_didLoadConfig");
			TDCallbacks.instance.OnTapdaqConfigLoaded ();
		}

		void _didFailToLoadConfig(string message) {
			TDDebugLogger.LogWarning ("_didFailToLoadConfig");
			var adEvent = JsonUtility.FromJson<TDAdError> (message);
			TDCallbacks.instance.OnTapdaqConfigFailedToLoad (adEvent);
		}
			
		void _didLoad (string jsonMessage) {
			TDDebugLogger.Log("_didLoad " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdAvailable (adEvent);
		}

		void _didFailToLoad (string jsonMessage) {
			TDDebugLogger.Log("_didFailToLoad " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdNotAvailable (adEvent);
		}

		void _didClose (string jsonMessage) {
			TDDebugLogger.Log("_didClose " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdClosed (adEvent);
		}

		void _didClick (string jsonMessage) {
			TDDebugLogger.Log("_onAdClick " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdClicked (adEvent);
		}

		void _didDisplay (string jsonMessage) {
			TDDebugLogger.Log("_didDisplay " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdDidDisplay (adEvent);
		}

		void _willDisplay (string jsonMessage) {
			TDDebugLogger.Log("_willDisplay " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdWillDisplay (adEvent);
		}

        void _didFailToDisplay(string jsonMessage)
        {
            TDDebugLogger.Log("_didFailToDisplay " + jsonMessage);
            var adEvent = JsonUtility.FromJson<TDAdEvent>(jsonMessage);
            TDCallbacks.instance.OnAdDidFailToDisplay(adEvent);
        }

		// video
		void _didComplete (string adType) {
			TDDebugLogger.Log("_didComplete " + adType);
		}

		void _didEngagement (string adType) {
			TDDebugLogger.Log("_didEngagement " + adType);
		}

		// reeward video
		void _didReachLimit (string adType) {
			TDDebugLogger.Log("_didReachLimit " + adType);
			TDCallbacks.instance.OnAdError (new TDAdEvent (adType, "VALIDATION_EXCEEDED_QUOTA"));
		}

		void _onRejected (string adType) {
			TDDebugLogger.Log("_onRejected " + adType);
			TDCallbacks.instance.OnAdError (new TDAdEvent (adType, "VALIDATION_REJECTED"));
		}

		void _didFail (string jsonMessage) {
			TDDebugLogger.Log("_didFail " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdError (adEvent);
		}

		void _onUserDeclined (string adType) {
			TDDebugLogger.Log("_onUserDeclined " + adType);
			TDCallbacks.instance.OnAdClosed (new TDAdEvent (adType, "DECLINED_TO_VIEW"));
		}

		void _didVerify (string message) {
			TDDebugLogger.Log("_didVerify " + message);
			var reward = JsonUtility.FromJson<TDVideoReward> (message);
			TDCallbacks.instance.OnRewardedVideoValidated (reward);
		}

		void _onValidationFailed(string jsonMessage) {
			TDDebugLogger.Log("_onValidationFailed " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdError (adEvent);
		}

		// banner
		void _didRefresh(string jsonMessage) {
			TDDebugLogger.Log ("_didRefresh " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent> (jsonMessage);
			TDCallbacks.instance.OnAdRefresh (adEvent);
		}

		void _didFailToRefresh(string jsonMessage)
		{
			TDDebugLogger.Log("_didFailToRefresh " + jsonMessage);
			var adEvent = JsonUtility.FromJson<TDAdEvent>(jsonMessage);
			TDCallbacks.instance.OnAdFailToRefresh(adEvent);
		}
	}
}