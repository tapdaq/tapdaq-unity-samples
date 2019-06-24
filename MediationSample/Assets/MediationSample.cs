﻿using System.Collections;
using System.Collections.Generic;
using System;
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
		TDCallbacks.TapdaqConfigFailedToLoad += FailedToLoadConfig;
		TDCallbacks.AdAvailable += AdAvailable;
		TDCallbacks.AdNotAvailable += AdNotAvailable;
		TDCallbacks.AdWillDisplay += AdWillDisplay;
		TDCallbacks.AdDidDisplay += AdDidDisplay;
		TDCallbacks.AdDidFailToDisplay += AdDidFailToDisplay;
		TDCallbacks.AdClicked += AdClicked;
		TDCallbacks.AdClosed += AdClosed;
		TDCallbacks.AdError += AdError;
		TDCallbacks.RewardVideoValidated += RewardVideoValidated;
		TDCallbacks.CustomEvent += CustomEvent;
	}

	// Unsubscribe from Tapdaq events
	private void OnDisable () {
		TDCallbacks.TapdaqConfigLoaded -= LoadConfig;
		TDCallbacks.TapdaqConfigFailedToLoad -= FailedToLoadConfig;
		TDCallbacks.AdAvailable -= AdAvailable;
		TDCallbacks.AdNotAvailable -= AdNotAvailable;
		TDCallbacks.AdWillDisplay -= AdWillDisplay;
		TDCallbacks.AdDidDisplay -= AdDidDisplay;
		TDCallbacks.AdDidFailToDisplay -= AdDidFailToDisplay;
		TDCallbacks.AdClicked -= AdClicked;
		TDCallbacks.AdClosed -= AdClosed;
		TDCallbacks.AdError -= AdError;
		TDCallbacks.RewardVideoValidated -= RewardVideoValidated;
		TDCallbacks.CustomEvent -= CustomEvent;
	}

    //Callback handlers
	private void LoadConfig() {
		//SDK BOOT COMPLETE
		Debug.Log("Tapdaq config loaded");
	}

    private void FailedToLoadConfig(TDAdError e) {
		LogError(e);
	}

	private void AdAvailable(TDAdEvent e) {
		Debug.Log("AdAvailable Type: " + e.adType + " - Tag: " + e.tag);
	}	

    private void AdNotAvailable(TDAdEvent e) {
		LogError(e.error);
	}

	private void AdWillDisplay(TDAdEvent e) {
		Debug.Log("AdWillDisplay Type: " + e.adType + " - Tag: " + e.tag);
	}

	private void AdDidDisplay(TDAdEvent e) {
		Debug.Log("AdDidDisplay Type: " + e.adType + " - Tag: " + e.tag);
	}

	private void AdDidFailToDisplay(TDAdEvent e) {	
		LogError(e.error);
	}

	private void AdClicked(TDAdEvent e) {
		Debug.Log("AdClicked Type: " + e.adType + " - Tag: " + e.tag);
	}

	private void AdClosed(TDAdEvent e) {
		Debug.Log("AdClosed Type: " + e.adType + " - Tag: " + e.tag);
	}

	private void AdError(TDAdEvent e) {
		LogError(e.error);
	}

    private void RewardVideoValidated(TDVideoReward e) {
		Debug.Log("RewardValidated name: " + e.RewardName + " - Tag: " + e.Tag + " - amount: " + e.RewardAmount);
	}

    private void CustomEvent(Dictionary<string, object> dictionary) {
		Debug.Log("CustomEvent dictionary:" + dictionary);
	}

	// Error logging
	private void LogError(TDAdError e) {
        Debug.Log("Code: " + e.code + " Message: " + e.message);
        foreach(KeyValuePair<String, List<TDAdError>> entry in e.subErrors) {
            Debug.Log("Code: " + e.code + "Message: " + e.message);
        }
	}


	// Load Ads
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


