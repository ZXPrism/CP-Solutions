class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int n = nums.size(), ans = 0, sum = 0;

        int tot = std::reduce(nums.begin(), nums.end());
        int target = tot - x;
        if (!target) {
            return n;
        }

        for (int left = 0, right = 0; right < n; right++) {
            sum += nums[right];
            while (left <= right && sum > target) {
                sum -= nums[left++];
            }
            if (sum == target) {
                ans = std::max(ans, right - left + 1);
            }
        }

        return (!ans ? -1 : n - ans);
    }
};
