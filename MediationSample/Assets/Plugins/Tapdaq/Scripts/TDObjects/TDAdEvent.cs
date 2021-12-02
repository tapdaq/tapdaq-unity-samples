﻿using System;

namespace Tapdaq {
	[Serializable]
	public class TDAdEvent {
		public string adType;
		public string message;
		public string tag;
		public TDAdError error;

		public TDAdEvent() {
		}

		public TDAdEvent(string adType, string message, string tag = null) {
			this.adType = adType;
			this.message = message;
			this.tag = tag;
		}

		public TDAdType GetTypeOfEvent()  {
			if (adType == "static_interstitial")
				return TDAdType.TDAdTypeInterstitial;
			
			if (adType == "banner")
				return TDAdType.TDAdTypeBanner;
			
			if (adType == "video_interstitial")
				return TDAdType.TDAdTypeVideo;
			
			if (adType == "rewarded_video_interstitial")
				return TDAdType.TDAdTypeRewardedVideo;
			return TDAdType.TDAdTypeNone;
		}

		public bool IsInterstitialEvent()  {
			return GetTypeOfEvent() == TDAdType.TDAdTypeInterstitial;
		}

		public bool IsVideoEvent()  {
			return GetTypeOfEvent() == TDAdType.TDAdTypeVideo;
		}

		public bool IsRewardedVideoEvent()  {
			return GetTypeOfEvent() == TDAdType.TDAdTypeRewardedVideo;
		}

		public bool IsBannerEvent()  {
			return GetTypeOfEvent() == TDAdType.TDAdTypeBanner;
		}
	}
}