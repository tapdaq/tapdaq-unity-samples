using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Tapdaq;
using Newtonsoft.Json;
#if UNITY_IOS
using Unity.Advertisement.IosSupport;
#endif

public class MediationSample : MonoBehaviour {

	private string mTag = "default";
    public Button initialiseBtn;
	public Button showStaticBtn;
	public Button showVideoBtn;
	public Button showRVBtn;
    public Button showRVWithUserIdBtn;
	public Button showBannerBtn;
    public Dropdown bannerSizeDropdown;
    public Dropdown bannerPositionDropdown;
    public InputField bannerXInput;
    public InputField bannerYInput;
    public InputField bannerWidthInput;
    public InputField bannerHeightInput;
    public Text logText;

	// Use this for initialization
	void Start () {
#if UNITY_IOS
		if(float.Parse(UnityEngine.iOS.Device.systemVersion) >= 14.0f)
        {
			Debug.Log("Unity iOS Support: Requesting iOS App Tracking Transparency native dialog.");

			ATTrackingStatusBinding.RequestAuthorizationTracking();
		}
#endif
    }

    private void Awake()
    {
        DontDestroyOnLoad(logText);
    }
    // Subscribe to Tapdaq events
    private void OnEnable () {
        TDCallbacks.TapdaqConfigLoaded += LoadedConfig;
		TDCallbacks.TapdaqConfigFailedToLoad += FailedToLoadConfig;
		TDCallbacks.AdAvailable += AdAvailable;
		TDCallbacks.AdNotAvailable += AdNotAvailable;
        TDCallbacks.AdRefresh += AdRefresh;
        TDCallbacks.AdFailToRefresh += AdFailedToRefresh;
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
        TDCallbacks.AdRefresh -= AdRefresh;
        TDCallbacks.AdFailToRefresh -= AdFailedToRefresh;
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

        //AdManager.SetUserSubjectToGdprStatus(TDStatus.TRUE);
        //AdManager.SetConsentStatus(TDStatus.FALSE);
        //AdManager.SetAgeRestrictedUserStatus(TDStatus.UNKNOWN);

        //TDStatus consentStatus = AdManager.GetConsentStatus();
        //TDStatus ageRestrictedUserStatus = AdManager.GetAgeRestrictedUserStatus();
        //string userId = AdManager.GetUserId();

        AdManager.Init ();
    }

    //Callback handlers
	private void LoadedConfig() {
        //SDK BOOT COMPLETE
        logMessage("LoadedConfig");

        bannerSizeDropdown.onValueChanged.AddListener(delegate {
            updateUI();
        });
        bannerPositionDropdown.onValueChanged.AddListener(delegate {
            updateUI();
        });
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

    private void AdRefresh(TDAdEvent e)
    {
        logMessage("AdRefresh: " + " - Tag: " + e.tag);
    }

    private void AdFailedToRefresh(TDAdEvent e)
    {
        logMessage("AdFailedToRefresh: " + stringifyError(e.error));
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
        string bannerSize = bannerSizeDropdown.options[bannerSizeDropdown.value].text;
        logMessage("LoadBanner " + bannerSize);
        TDMBannerSize size;
        if(bannerSize.Equals("Custom"))
        {
            int width;
            int height;
            int.TryParse(bannerWidthInput.text, out width);
            int.TryParse(bannerHeightInput.text, out height);
            AdManager.RequestBanner(width, height, mTag);
        } else
        {
            if (bannerSize.Equals("Standard"))
            {
                size = TDMBannerSize.TDMBannerStandard;
            }
            else if (bannerSize.Equals("Medium"))
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
            else if (bannerSize.Equals("Smart"))
            {
                size = TDMBannerSize.TDMBannerSmart;
            }
            else
            {
                size = TDMBannerSize.TDMBannerStandard;
            }
            AdManager.RequestBanner(size, mTag);
        }
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
        if(AdManager.IsBannerReady(mTag)) {
            string position = bannerPositionDropdown.options[bannerPositionDropdown.value].text;
            TDBannerPosition bannerPosition = TDBannerPosition.Bottom;
            if(position.Equals("Custom"))
            {
                int x = 0;
                int y = 0;
                int.TryParse(bannerXInput.text, out x);
                int.TryParse(bannerYInput.text, out y);
                AdManager.ShowBanner(x, y, mTag);
                return;
            } else if (position.Equals("Bottom"))
            {
                bannerPosition = TDBannerPosition.Bottom;
            } else if (position.Equals("Top"))
            {
                bannerPosition = TDBannerPosition.Top;
            }
            AdManager.ShowBanner(bannerPosition, mTag);
        } else {
            logMessage("Banner is not ready");
        }
        updateUI();
	}

    public void HideBanner()
    {
        logMessage("HideBanner");
        AdManager.HideBanner(mTag);
        updateUI();
    }

    public void DestroyBanner()
    {
        logMessage("DestroyBanner");
        AdManager.DestroyBanner(mTag);
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
        showBannerBtn.image.color = (AdManager.IsBannerReady(mTag) ? Color.green : Color.red);
        showVideoBtn.image.color = (AdManager.IsVideoReady(mTag) ? Color.green : Color.red);
        showRVBtn.image.color = showRVWithUserIdBtn.image.color = (AdManager.IsRewardedVideoReady(mTag) ? Color.green : Color.red);

        TDBannerPosition position = getBannerPosition(bannerPositionDropdown.options[bannerPositionDropdown.value].text);
        TDMBannerSize size = getBannerSize(bannerSizeDropdown.options[bannerSizeDropdown.value].text);
        bannerXInput.interactable = bannerYInput.interactable = (position == TDBannerPosition.Custom);
        bannerWidthInput.interactable = bannerHeightInput.interactable = (size == TDMBannerSize.TDMBannerCustom);
    }

    private string stringifyError(TDAdError e) {
        string str = e.code + " - " + e.message;
        if(e.subErrors != null)
        {
            foreach (KeyValuePair<string, List<TDAdError>> entry in e.subErrors)
            {
                str += "\n" + entry.Key;
                foreach (TDAdError subError in entry.Value)
                {
                    str += "\n" + subError.code + " - " + subError.message;
                }
            }
        }

        return str;
    }

    private TDMBannerSize getBannerSize(string sizeStr)
    {
        if (sizeStr.Equals("Standard"))
            return TDMBannerSize.TDMBannerStandard;
        else if (sizeStr.Equals("Medium"))
            return TDMBannerSize.TDMBannerMedium;
        else if (sizeStr.Equals("Large"))
            return TDMBannerSize.TDMBannerLarge;
        else if (sizeStr.Equals("Full"))
            return TDMBannerSize.TDMBannerFull;
        else if (sizeStr.Equals("Leaderboard"))
            return TDMBannerSize.TDMBannerLeaderboard;
        else if (sizeStr.Equals("Smart"))
            return TDMBannerSize.TDMBannerSmart;
        else if (sizeStr.Equals("Custom"))
            return TDMBannerSize.TDMBannerCustom;
        return TDMBannerSize.TDMBannerStandard;
    }

    private TDBannerPosition getBannerPosition(string positionStr)
    {
        if (positionStr.Equals("Top"))
            return TDBannerPosition.Top;
        else if (positionStr.Equals("Bottom"))
            return TDBannerPosition.Bottom;
        else if (positionStr.Equals("Custom"))
            return TDBannerPosition.Custom;
        return TDBannerPosition.Bottom;
    }
}


