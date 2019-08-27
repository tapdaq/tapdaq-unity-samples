using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Tapdaq;
using Newtonsoft.Json;

public class MediationSample : MonoBehaviour {

	private string mTag = "default";
    public Button initialiseBtn;
	public Button showStaticBtn;
	public Button showVideoBtn;
	public Button showRVBtn;
    public Button showRVWithUserIdBtn;
	public Button showBannerBtn;
    public Button hideBannerBtn;
    public Dropdown bannerDropdown;
    public Text logText;

	// Use this for initialization
	void Start () {
			
	}

	// Subscribe to Tapdaq events
	private void OnEnable () {
        TDCallbacks.TapdaqConfigLoaded += LoadedConfig;
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
	}

	// Unsubscribe from Tapdaq events
	private void OnDisable () {
        TDCallbacks.TapdaqConfigLoaded -= LoadedConfig;
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
	}

    public void OnClickInitialise() {
        logMessage("OnClickInitialise");
        TDStatus consentStatus = (AdManager.IsConsentGiven() ? TDStatus.TRUE : TDStatus.FALSE);
        TDStatus ageRestrictedUserStatus = (AdManager.IsAgeRestrictedUser() ? TDStatus.TRUE : TDStatus.FALSE);
        string userId = AdManager.GetUserId();

        AdManager.Init (AdManager.IsUserSubjectToGDPR(), consentStatus, ageRestrictedUserStatus, userId, AdManager.ShouldForwardUserId());
    }

    //Callback handlers
	private void LoadedConfig() {
        //SDK BOOT COMPLETE
        logMessage("LoadedConfig");
	}

    private void FailedToLoadConfig(TDAdError e) {
        logMessage("FailedToLoadConfig: " + stringifyError(e));
	}

	private void AdAvailable(TDAdEvent e) {
        logMessage("AdAvailable Type: " + e.adType + " - Tag: " + e.tag);

        updateUI();
	}	

    private void AdNotAvailable(TDAdEvent e) {
        logMessage("AdNotAvailable: " + stringifyError(e.error));
	}

	private void AdWillDisplay(TDAdEvent e) {
        logMessage("AdWillDisplayType: " + e.adType + " - Tag: " + e.tag);
	}

	private void AdDidDisplay(TDAdEvent e) {
        logMessage("AdDidDisplay Type: " + e.adType + " - Tag: " + e.tag);
	}

	private void AdDidFailToDisplay(TDAdEvent e) {
        logMessage("AdDidFailToDisplay: " + stringifyError(e.error));
	}

	private void AdClicked(TDAdEvent e) {
        logMessage("AdClicked Type: " + e.adType + " - Tag: " + e.tag);
	}

	private void AdClosed(TDAdEvent e) {
        logMessage("AdClosed Type: " + e.adType + " - Tag: " + e.tag);

        updateUI();
	}

	private void AdError(TDAdEvent e) {
        logMessage("AdError: " + stringifyError(e.error));
	}

    private void RewardVideoValidated(TDVideoReward e) {
        logMessage("RewardVideoValidated isValud: " + e.RewardValid + " - name: " + e.RewardName + " - Tag: " + e.Tag + " - amount: " + e.RewardAmount + " - CustomJson: " + JsonConvert.SerializeObject(e.RewardJson));
	}

	// Load Ads
    public void LoadStaticInterstitial() {
        logMessage("LoadStaticInterstitial");
		AdManager.LoadInterstitial (mTag);
	}

    public void LoadVideoInterstitial() {
        logMessage("LoadVideoInterstitial");
		AdManager.LoadVideo (mTag);
	}

    public void LoadRewardedVideoInterstitial() {
        logMessage("LoadRewardedVideoInterstitial");
		AdManager.LoadRewardedVideo (mTag);
	}

	public void LoadBanner() {
        string bannerSize = bannerDropdown.options[bannerDropdown.value].text;
        logMessage("LoadBanner " + bannerSize);
        TDMBannerSize size;
        if(bannerSize.Equals("Standard")) {
            size = TDMBannerSize.TDMBannerStandard;
        } else if (bannerSize.Equals("Medium"))
        {
            size = TDMBannerSize.TDMBannerMedium;
        }
        else if (bannerSize.Equals("Large"))
        {
            size = TDMBannerSize.TDMBannerLarge;
        }
        else if (bannerSize.Equals("Full"))
        {
            size = TDMBannerSize.TDMBannerFull;
        }
        else if (bannerSize.Equals("Leaderboard"))
        {
            size = TDMBannerSize.TDMBannerLeaderboard;
        }
        else if (bannerSize.Equals("Smart Portrait"))
        {
            size = TDMBannerSize.TDMBannerSmartPortrait;
        } else if (bannerSize.Equals("Smart Landscape"))
        {
            size = TDMBannerSize.TDMBannerSmartPortrait;
        } else {
            size = TDMBannerSize.TDMBannerStandard;
        }
        AdManager.RequestBanner (size);
	}

    public void ShowStaticInterstitial() {
        logMessage("ShowStaticInterstitial");
		AdManager.ShowInterstitial (mTag);
	}

    public void ShowVideoInterstitial() {
        logMessage("ShowVideoInterstitial");
		AdManager.ShowVideo (mTag);
	}

    public void ShowRewardedVideoInterstitial() {
        logMessage("ShowRewardedVideoInterstitial");
		AdManager.ShowRewardVideo (mTag);
	}

    public void ShowRewardedVideoInterstitialWithUserId()
    {
        logMessage("ShowRewardedVideoInterstitial");
        AdManager.ShowRewardVideo(mTag, AdManager.GetUserId());
    }

    public void ShowBanner() {
        logMessage("ShowBanner");
        if(AdManager.IsBannerReady()) {
            AdManager.ShowBanner(TDBannerPosition.Bottom);
        } else {
            logMessage("Banner is not ready");
        }
        updateUI();
	}

    public void HideBanner()
    {
        logMessage("HideBanner");
        AdManager.HideBanner();
        updateUI();
    }

    public void ShowDebugger() {
        logMessage("ShowDebugger");
		AdManager.LaunchMediationDebugger ();
	}

    public void SetPlacementName(InputField placementField) {
        logMessage("SetPlacementName " + placementField.text);
		mTag = placementField.text;
        updateUI();
    }

    private void logMessage(string message) {
        Debug.Log(message);
        logText.text = System.DateTime.Now.ToString("yyyy-MM-dd HH:mm:ss") + " " + message + "\n" + logText.text;
    }

    private void updateUI() {
        showStaticBtn.image.color = (AdManager.IsInterstitialReady(mTag) ? Color.green : Color.red);
        showBannerBtn.image.color = (AdManager.IsBannerReady() ? Color.green : Color.red);
        showVideoBtn.image.color = (AdManager.IsVideoReady(mTag) ? Color.green : Color.red);
        showRVBtn.image.color = showRVWithUserIdBtn.image.color = (AdManager.IsRewardedVideoReady(mTag) ? Color.green : Color.red);
    }

    private string stringifyError(TDAdError e) {
        string str = e.code + " - " + e.message;
        foreach (KeyValuePair<string, List<TDAdError>> entry in e.subErrors)
        {
            str += "\n" + entry.Key;
            foreach(TDAdError subError in entry.Value) {
                str += "\n" + subError.code + " - " + subError.message;
            }
        }
        return str;
    }
}


