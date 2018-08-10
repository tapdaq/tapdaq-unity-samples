using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Tapdaq;
public class InterstitialBootup : MonoBehaviour {

    public void StartDebugger()    {
        AdManager.LaunchMediationDebugger();
    }

    // Subscribe from Tapdaq events
    private void OnEnable() {
		
		TDCallbacks.AdAvailable += OnAdAvailable;
		TDCallbacks.TapdaqConfigLoaded += OnTapdaqConfigLoaded; 
	}

	// Unsubscribe from Tapdaq events
	private void OnDisable() {
		TDCallbacks.AdAvailable -= OnAdAvailable;
		TDCallbacks.TapdaqConfigLoaded -= OnTapdaqConfigLoaded;
	}

	private void Start() {
		AdManager.Init();
	}

	private void OnTapdaqConfigLoaded() {
		AdManager.LoadInterstitial("main_menu");
	}

	// Change main_menu to an activated placement tag. Remember to add app id and client key in Window -> Tapdaq -> Edit Settings.
	private void OnAdAvailable(TDAdEvent e) {   
		if (e.adType == "INTERSTITIAL" && e.tag == "main_menu") {
			AdManager.ShowInterstitial("main_menu");
		}
	}
}
