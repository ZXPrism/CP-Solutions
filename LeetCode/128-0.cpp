class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        std::unordered_set<int> exist(nums.begin(), nums.end());
        std::unordered_set<int> consumed;
        std::unordered_map<int, int> dp;
        int ans = 0;
        for (auto elem : nums) {
            if (consumed.contains(elem)) {
                continue;
            }

            int curr = elem;
            while (exist.contains(curr)) {
                if (consumed.contains(curr)) {
                    curr += dp[curr];
                    break;
                }
                consumed.insert(curr);
                ++curr;
            }

            dp[elem] = curr - elem;
            ans = std::max(ans, curr - elem);
        }

        return ans;
    }
};
