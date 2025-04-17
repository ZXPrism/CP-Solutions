class Solution {
public:
	int threeSumMulti(vector<int> &arr, int target) {
		std::ranges::sort(arr);
		int n = arr.size(), ans = 0;
		constexpr int MOD = 1'000'000'007;
		for (int i = 0; i < n; i++) {
			int left = i + 1, right = n - 1, t = target - arr[i];
			while (left < right) {
				int sum = arr[left] + arr[right];
				if (sum < t) {
					++left;
				} else if (sum > t) {
					--right;
				} else if (arr[left] != arr[right]) {
					int l = left;
					while (left <= right && arr[left] == arr[l]) {
						++left;
					}
					int r = right;
					while (left <= right && arr[right] == arr[r]) {
						--right;
					}
					ans = (ans + 1LL * (left - l) * (r - right)) % MOD;
				} else {
					ans =
					    (ans + 1LL * (right - left + 1) * (right - left) / 2) %
					    MOD;
					break;
				}
			}
		}
		return ans;
	}
};
