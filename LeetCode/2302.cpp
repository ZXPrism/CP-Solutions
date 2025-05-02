class Solution {
public:
	long long countSubarrays(vector<int> &nums, long long k) {
		long long ans = 0;
		int n = nums.size();
		long long sum = 0;
		for (int left = 0, right = 0; right < n; right++) {
			sum += nums[right];
			while (sum * (right - left + 1) >= k) {
				sum -= nums[left];
				++left;
			}
			ans += right - left + 1;
		}
		return ans;
	}
};
