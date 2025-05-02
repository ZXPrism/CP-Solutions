class Solution {
public:
	long long countSubarrays(vector<int> &nums, int k) {
		long long ans = 0;
		int target = *std::ranges::max_element(nums), n = nums.size(), cnt = 0;
		for (int left = 0, right = 0; right < n; right++) {
			cnt += (nums[right] == target);
			while (cnt >= k) {
				cnt -= (nums[left] == target);
				++left;
			}
			ans += left;
		}
		return ans;
	}
};
