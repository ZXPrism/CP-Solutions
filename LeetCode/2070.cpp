class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>> &items, vector<int> &queries) {
        std::ranges::sort(items, [&](auto &lhs, auto &rhs) { return lhs[0] < rhs[0]; });
        int n = items.size();
        std::vector<int> preMax(n + 1);
        for (int i = 0; i < n; i++) {
            preMax[i + 1] = std::max(preMax[i], items[i][1]);
        }

        int q = queries.size();
        std::vector<int> ans(q);
        for (int i = 0; i < q; i++) {
            int left = -1, right = n, mid = 0;
            while (left + 1 < right) {
                mid = (left + right) / 2;
                if (items[mid][0] <= queries[i]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            ans[i] = preMax[left + 1];
        }

        return ans;
    }
};
