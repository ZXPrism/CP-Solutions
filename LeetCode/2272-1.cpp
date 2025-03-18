class Solution {
public:
    int largestVariance(string s) {
        constexpr int INF = std::numeric_limits<int>::max();
        int ans = 0, n = s.size();
        std::vector<std::vector<int>> f0(26, std::vector<int>(26));
        std::vector<std::vector<int>> f1(26, std::vector<int>(26, -INF));
        for (auto ch : s) {
            ch -= 'a';
            for (int i = 0; i < 26; i++) {
                if (ch == i) {
                    continue;
                }
                f0[ch][i] = std::max(f0[ch][i], 0) + 1;
                ++f1[ch][i];

                f0[i][ch] = std::max(f0[i][ch], 0) - 1;
                f1[i][ch] = f0[i][ch];

                ans = std::max({ans, f1[ch][i], f1[i][ch]});
            }
        }
        return ans;
    }
};
