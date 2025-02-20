class Solution {
public:
    vector<int> getTriggerTime(vector<vector<int>> &increase, vector<vector<int>> &requirements) {
        int n = increase.size(), q = requirements.size();

        std::vector<std::vector<int>> pre(3, std::vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                pre[j][i + 1] = pre[j][i] + increase[i][j];
            }
        }

        std::vector<int> ans(q, -1);
        for (int i = 0; i < q; i++) {
            int a = std::ranges::lower_bound(pre[0], requirements[i][0]) - pre[0].begin();
            int b = std::ranges::lower_bound(pre[1], requirements[i][1]) - pre[1].begin();
            int c = std::ranges::lower_bound(pre[2], requirements[i][2]) - pre[2].begin();
            if (a != n + 1 && b != n + 1 && c != n + 1) {
                ans[i] = std::max({a, b, c});
            }
        }

        return ans;
    }
};
