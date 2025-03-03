class Solution {
public:
    int longestEqualSubarray(vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<std::vector<int>> val2pos(n + 1);
        for (int i = 0; i < n; i++) {
            val2pos[nums[i]].push_back(i);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            auto &pos = val2pos[i];
            int n_pos = pos.size();
            for (int left = 0, right = 0; right < n_pos; right++) {
                while (left < right && pos[right] - pos[left] + 1 - (right - left + 1) > k) {
                    ++left;
                }
                ans = std::max(ans, right - left + 1);
            }
        }
        return ans;
    }
};
