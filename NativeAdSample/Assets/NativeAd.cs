using UnityEngine;
using UnityEngine.UI;
using System.Collections;
using Tapdaq;

public class NativeAd : MonoBehaviour {

	public Image nativeAdImage;
	private Sprite nativeAdSprite;
	private TDNativeAd ad;
	private string tag = "default";

	// Use this for initialization
	void Start () {
		AdManager.Init (); //Initialise Tapdaq
	}

    public void StartDebugger()
    {
        AdManager.LaunchMediationDebugger();
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
		LoadAd ();
	}

	private void AdAvailable(TDAdEvent e) {
		if (e.adType.Equals ("NATIVE_AD")) {
			if (e.tag.Equals (e.tag)) {
				ShowAd (); //Show Immediately. Disable this to use the Show button
			}
		}
	}		
		
	public void LoadAd() {
		AdManager.LoadNativeAdvertForTag (tag, TDNativeAdType.TDNativeAdType1x1Large);
	}

	public void ShowAd() {
		ad = AdManager.GetNativeAd (TDNativeAdType.TDNativeAdType1x1Large, tag);
		ad.LoadTexture((TDNativeAd obj) => {
			if (ad != null) {
				nativeAdSprite = Sprite.Create(ad.texture, new Rect(0,0, ad.texture.width, ad.texture.height), Vector2.one * 0.5f);
				nativeAdImage.sprite = nativeAdSprite;
				AdManager.SendNativeImpression (ad);
			}
		});
	}

	public void ClickNativeAd() {
		AdManager.SendNativeClick (ad);
	}

	public void ClearAd() {
		ad = null;
		nativeAdImage.sprite = null;
	}
}
