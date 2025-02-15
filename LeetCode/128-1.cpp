class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int ans = 0;
        std::unordered_set<int> exist(nums.begin(), nums.end());
        for (auto elem : exist) {
            if (exist.contains(elem - 1)) {
                continue;
            }
            int right = elem;
            while (exist.contains(right)) {
                ++right;
            }
            ans = std::max(ans, right - elem);
        }
        return ans;
    }
};
