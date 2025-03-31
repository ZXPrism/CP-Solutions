class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int row = matrix.size(), col = matrix[0].size(), ans = 0;

        std::vector<std::vector<int>> pre(row, std::vector<int>(col + 1));
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                pre[i][j + 1] = pre[i][j] + (matrix[i][j] - '0');
            }
        }

        for (int i = 0; i < col; i++) {
            for (int j = i; j < col; j++) {
                int len = j - i + 1;
                int left = 0;
                while (left < row) {
                    if (pre[left][j + 1] - pre[left][i] != len) {
                        ++left;
                        continue;
                    }
                    int right = left + 1;
                    while (right < row && pre[right][j + 1] - pre[right][i] == len) {
                        ++right;
                    }
                    ans = std::max(ans, (right - left) * len);
                    left = right;
                }
            }
        }

        return ans;
    }
};
