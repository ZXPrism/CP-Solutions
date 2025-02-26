class Solution {
public:
    int maxSubarraySumCircular(vector<int> &nums) {
        int n = nums.size(), INF = std::numeric_limits<int>::max();

        std::vector<int> preMax(n + 1);
        preMax[0] = -INF;
        int max_1 = -INF, max_curr = 0, pre = 0;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            preMax[i + 1] = std::max(preMax[i], pre);
            max_curr = std::max(max_curr + nums[i], nums[i]);
            max_1 = std::max(max_1, max_curr);
        }

        int max_2 = -INF, suf = 0;
        for (int i = n - 1; i > 0; i--) {
            suf += nums[i];
            max_2 = std::max(max_2, suf + preMax[i]);
        }

        return std::max(max_1, max_2);
    }
};
