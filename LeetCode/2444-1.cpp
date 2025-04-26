class Solution {
public:
	long long countSubarrays(vector<int> &nums, int minK, int maxK) {
		long long ans = 0;
		int mink_idx = -1, maxk_idx = -1, n = nums.size();
		int other_idx = -1;
		for (int i = 0; i < n; i++) {
			if (nums[i] == minK) {
				mink_idx = i;
			}
			if (nums[i] == maxK) {
				maxk_idx = i;
			}
			if (nums[i] < minK || nums[i] > maxK) {
				other_idx = i;
			}
			int start = std::min(mink_idx, maxk_idx);
			ans += std::max(0, start - other_idx);
		}
		return ans;
	}
};
