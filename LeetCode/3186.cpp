class Solution {
public:
    long long maximumTotalDamage(vector<int> &power) {
        std::map<int, int> cnt;
        for (auto elem : power) {
            ++cnt[elem];
        }
        std::vector<std::pair<int, int>> v(cnt.begin(), cnt.end());

        int n = v.size();
        std::vector<long long> dp(n + 3);
        for (int i = 0; i < n; i++) {
            int j = i - 1;
            while (j >= 0 && v[j].first >= v[i].first - 2) {
                --j;
            }
            dp[i + 3] = std::max(dp[i + 2], dp[j + 3] + 1LL * v[i].first * v[i].second);
        }

        return dp[n + 2];
    }
};
