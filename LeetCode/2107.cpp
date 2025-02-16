class Solution {
public:
    int shareCandies(vector<int> &candies, int k) {
        int n = candies.size();

        int unique = 0;
        std::vector<int> cnt(100'001);
        for (auto elem : candies) {
            if (++cnt[elem] == 1) {
                ++unique;
            }
        }
        if (k == 0) {
            return unique;
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (--cnt[candies[i]] == 0) {
                --unique;
            }
            if (i >= k - 1) {
                ans = std::max(ans, unique);
                if (++cnt[candies[i - k + 1]] == 1) {
                    ++unique;
                }
            }
        }

        return ans;
    }
};
