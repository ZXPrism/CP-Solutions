class Solution {
public:
    bool exist(vector<vector<char>> &board, string word) {
        int m = board.size(), n = board[0].size(), n_word = word.size();
        std::vector<std::vector<int>> vis(m, std::vector<int>(n));
        constexpr int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        auto dfs = [&](this auto &&dfs, int x, int y, int k) -> bool {
            if (word[k] != board[x][y]) {
                return false;
            } else if (k == n_word - 1) {
                return true;
            }
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    if (dfs(nx, ny, k + 1)) {
                        return true;
                    }
                    vis[nx][ny] = 0;
                }
            }
            return false;
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vis[i][j] = 1;
                if (board[i][j] == word[0] && dfs(i, j, 0)) {
                    return true;
                }
                vis[i][j] = 0;
            }
        }
        return false;
    }
};
