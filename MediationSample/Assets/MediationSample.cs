using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Tapdaq;

public class MediationSample : MonoBehaviour {

	private string mTag = "default";

	// Use this for initialization
	void Start () {
		AdManager.Init ();
	}
	
	// Subscribe to Tapdaq events
	private void OnEnable () {
		TDCallbacks.TapdaqConfigLoaded += LoadConfig;
		TDCallbacks.AdAvailable += AdAvailable;
	}

	// Unsubscribe from Tapdaq events
	private void OnDisable () {
		TDCallbacks.TapdaqConfigLoaded -= LoadConfig;
		TDCallbacks.AdAvailable -= AdAvailable;
	}

	private void LoadConfig() {
		//SDK BOOT COMPLETE
	}

	private void AdAvailable(TDAdEvent e) {
		Debug.Log ("AdAvailable Type: " + e.adType + " - Tag: " + e.tag);
	}	

	public void LoadStaticInterstitial() {
		AdManager.LoadInterstitial (mTag);
	}

	public void LoadVideoInterstitial() {
		AdManager.LoadVideo (mTag);
	}

	public void LoadRewardedVideoInterstitial() {
		AdManager.LoadRewardedVideo (mTag);
	}

	public void LoadBanner() {
		AdManager.RequestBanner (TDMBannerSize.TDMBannerStandard);
	}

	public void ShowStaticInterstitial() {
		AdManager.ShowInterstitial (mTag);
	}

	public void ShowVideoInterstitial() {
		AdManager.ShowVideo (mTag);
	}

	public void ShowRewardedVideoInterstitial() {
		AdManager.ShowRewardVideo (mTag);
	}

	public void ShowBanner() {
		AdManager.ShowBanner (TDBannerPosition.Bottom);
	}

	public void ShowDebugger() {
		AdManager.LaunchMediationDebugger ();
	}

    public void SetPlacementName(InputField placementField) {
		mTag = placementField.text;
    }
}
