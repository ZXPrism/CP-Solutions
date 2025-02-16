class Solution {
public:
    double findMaxAverage(vector<int> &nums, int k) {
        double ans = -10001;
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (i >= k - 1) {
                ans = std::max(ans, 1.0 * sum / k);
                sum -= nums[i - k + 1];
            }
        }
        return ans;
    }
};
