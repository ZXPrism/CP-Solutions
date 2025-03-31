class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<int> ans(n - k + 1);
        std::deque<int> maxq;
        for (int i = 0; i < n; i++) {
            while (!maxq.empty() && nums[i] >= nums[maxq.back()]) {
                maxq.pop_back();
            }
            maxq.push_back(i);
            if (i >= k - 1) {
                while (maxq.front() < i - k + 1) {
                    maxq.pop_front();
                }
                ans[i - k + 1] = nums[maxq.front()];
            }
        }
        return ans;
    }
};
