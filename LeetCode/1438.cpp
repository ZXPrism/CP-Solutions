class Solution {
public:
    int longestSubarray(vector<int> &nums, int limit) {
        int n = nums.size(), ans = 0;
        std::deque<int> qmx, qmi;
        for (int left = 0, right = 0; right < n; right++) {
            while (!qmx.empty() && nums[right] >= nums[qmx.back()]) {
                qmx.pop_back();
            }
            qmx.push_back(right);
            while (!qmi.empty() && nums[right] <= nums[qmi.back()]) {
                qmi.pop_back();
            }
            qmi.push_back(right);
            while (nums[qmx.front()] - nums[qmi.front()] > limit) {
                ++left;
                while (qmx.front() < left) {
                    qmx.pop_front();
                }
                while (qmi.front() < left) {
                    qmi.pop_front();
                }
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
