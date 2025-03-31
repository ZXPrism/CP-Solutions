class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            std::vector<std::vector<int>> ans(numRows);
            for (int i = 0; i < numRows; i++) {
                ans[i].resize(i + 1);
                if (i == 0) {
                    ans[0][0] = 1;
                    continue;
                }
                for (int j = 0; j <= i; j++) {
                    if (j != 0) {
                        ans[i][j] += ans[i - 1][j - 1];
                    }
                    if (j != i) {
                        ans[i][j] += ans[i - 1][j];
                    }
                }
            }
            return ans;
        }
    };
