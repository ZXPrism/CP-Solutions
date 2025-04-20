class Solution {
public:
	long long countBadPairs(vector<int> &nums) {
		long long ans = 0;
		int n = nums.size();
		std::unordered_map<int, int> cnt;
		for (int i = 0; i < n; i++) {
			int eigen = nums[i] - i;
			ans += cnt[eigen];
			++cnt[eigen];
		}
		return 1LL * n * (n - 1) / 2 - ans;
	}
};
