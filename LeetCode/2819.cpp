class Solution {
public:
    vector<long long> minimumRelativeLosses(vector<int> &prices, vector<vector<int>> &queries) {
        int n = prices.size(), q = queries.size();

        std::ranges::sort(prices);
        std::vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + prices[i];
        }

        std::vector<long long> ans(q);
        for (int i = 0; i < q; i++) {
            int k = queries[i][0], m = queries[i][1];
            int b0 = n - (std::ranges::upper_bound(prices, k) - prices.begin());
            int left = std::max(m - n + b0, 0) - 1, right = std::min(m, b0), mid = 0;
            auto F = [&](int b) -> long long {
                return 2LL * b * k + pre[m - b] - (pre[n] - pre[n - b]);
            };

            while (left + 1 < right) {
                mid = (left + right) >> 1;
                if (F(mid) >= F(mid + 1)) {
                    left = mid;
                } else {
                    right = mid;
                }
            }

            ans[i] = F(right);
        }

        return ans;
    }
};
