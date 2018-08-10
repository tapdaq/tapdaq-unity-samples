using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;
using Tapdaq;

public class MoreAppsSample : MonoBehaviour {

	[SerializeField] private Button loadMoreAppsButton;
	[SerializeField] private Button showMoreAppsButton;

	// Use this for initialization
	void Start () {
		loadMoreAppsButton.interactable = false;
		showMoreAppsButton.interactable = false;

		AdManager.Init ();
	}

    public void StartDebugger()
    {
        AdManager.LaunchMediationDebugger();
    }

    private void OnEnable () {
		TDCallbacks.TapdaqConfigLoaded += OnTapdaqConfigLoaded;
		TDCallbacks.AdAvailable += OnAdAvailable;
	}

	private void OnDisable () {
		TDCallbacks.TapdaqConfigLoaded -= OnTapdaqConfigLoaded;
		TDCallbacks.AdAvailable -= OnAdAvailable;
	}

	public void Load() {
		TDMoreAppsConfig config = new TDMoreAppsConfig ();

		AdManager.LoadMoreAppsWithConfig (config);
	}

	public void Show() {
		AdManager.ShowMoreApps ();
	}

	private void OnTapdaqConfigLoaded() {
		loadMoreAppsButton.interactable = true;
	}

	private void OnAdAvailable (TDAdEvent e) {
		if (e.adType == "MORE_APPS") {
			showMoreAppsButton.interactable = true;
			Debug.Log ("-- Test Log -- More Apps is available. Tag = " + e.tag);
			Debug.Log ("Is ready = " + AdManager.IsMoreAppsReady());
		}
	}
}
