class Solution {
public:
	long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
		int n = nums.size();
		std::vector<int> pre(n + 1);
		for (int i = 0; i < n; i++) {
			pre[i + 1] = (pre[i] + (nums[i] % modulo == k)) % modulo;
		}
		long long ans = 0;
		std::vector<int> cnt(std::min(n + 1, modulo));
		++cnt[0];
		for (int i = 0; i < n; i++) {
			if (pre[i + 1] >= k) {
				ans += cnt[pre[i + 1] - k];
			}
			if (pre[i + 1] + modulo - k < cnt.size()) {
				ans += cnt[pre[i + 1] + modulo - k];
			}
			++cnt[pre[i + 1]];
		}
		return ans;
	}
};
