class Solution {
public:
    vector<int> shortestDistanceColor(vector<int> &colors, vector<vector<int>> &queries) {
        std::vector<std::vector<int>> pos(4);
        int n = colors.size();
        for (int i = 0; i < n; i++) {
            pos[colors[i]].push_back(i);
        }
        int q = queries.size();
        std::vector<int> ans(q, n);
        for (int i = 0; i < q; i++) {
            int idx = queries[i][0], color = queries[i][1];
            if (pos[color].empty()) {
                ans[i] = -1;
            } else {
                int x = std::ranges::lower_bound(pos[color], idx) - pos[color].begin();
                if (x != pos[color].size()) {
                    ans[i] = std::min(ans[i], std::abs(pos[color][x] - idx));
                }
                if (x != 0) {
                    ans[i] = std::min(ans[i], std::abs(pos[color][x - 1] - idx));
                }
            }
        }
        return ans;
    }
};
