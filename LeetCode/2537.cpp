class Solution {
public:
	long long countGood(vector<int> &nums, int k) {
		long long ans = 0;
		int n = nums.size();
		std::unordered_map<int, int> cnt;
		long long curr_cnt = 0;
		for (int left = 0, right = 0; right < n; right++) {
			curr_cnt += cnt[nums[right]];
			++cnt[nums[right]];
			while (curr_cnt >= k) {
				curr_cnt -= cnt[nums[left]] - 1;
				--cnt[nums[left]];
				++left;
			}
			ans += left;
		}
		return ans;
	}
};
