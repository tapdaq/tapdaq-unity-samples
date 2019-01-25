using System;

namespace Tapdaq {

	public static class TDEnumHelper {

		public static string FixAndroidAdapterName(string adapterName) {
			if (adapterName == Enum.GetName (typeof(TapdaqAdapter), TapdaqAdapter.FANAdapter)) {
				return "FacebookAdapter";
			}
			return adapterName;
		}

		public static T GetEnumFromString<T>(string enumString, T defaultValue = default(T)) {
			Array values = null;
			try {
				values = Enum.GetValues (typeof(T));
			}
			catch(Exception e) {
				TDDebugLogger.LogError ("Can't GetEnumFromString: " + enumString);
				return defaultValue;
			}

			if (values == null)
				return defaultValue;

			foreach (var val in values) {
				if (val.ToString ().ToLower () == enumString.ToLower())
					return (T)val;
			}

			return defaultValue;
		}
	}
}
