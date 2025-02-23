class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition,
                          vector<int> &stock, vector<int> &cost) {
        int ans = 0;
        for (int i = 0; i < k; i++) {
            int left = -1, right = static_cast<int>(1e9), mid = 0;

            auto check = [&](int cnt) -> bool {
                long long tot = 0;
                for (int j = 0; j < n; j++) {
                    tot += cost[j] * std::max(0LL, 1LL * cnt * composition[i][j] - stock[j]);
                }
                return tot <= budget;
            };

            while (left + 1 < right) {
                mid = (left + right) >> 1;
                if (check(mid)) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            ans = std::max(ans, left);
        }
        return ans;
    }
};
