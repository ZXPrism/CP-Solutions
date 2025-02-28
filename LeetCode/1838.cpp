class Solution {
public:
    int maxFrequency(vector<int> &nums, int k) {
        // ((r - l + 1) * nums[r] - sum(l..r)) <= k, argmax len
        // delta = (r - l + 2) * nums[r + 1] - sum(l..r+1)
        // - (r - l + 1) * nums[r] + sum(l..r)
        // = (r - l + 1) * (nums[r + 1] - nums[r]) + nums[r + 1] - nums[r + 1]
        // >= 0
        std::ranges::sort(nums);
        int n = nums.size(), ans = 0;
        long long sum = 0;

        auto F = [&](int left, int right, long long sum) -> bool {
            return 1LL * (right - left + 1) * nums[right] - sum > k;
        };

        for (int left = 0, right = 0; right < n; right++) {
            sum += nums[right];
            while (left <= right && F(left, right, sum)) {
                sum -= nums[left++];
            }
            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};
