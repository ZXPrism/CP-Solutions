class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;
        std::vector<int> fa(m * n, -1);
        auto Find = [&](auto &&self, int x) -> int {
            return (fa[x] < 0 ? x : fa[x] = self(self, fa[x]));
        };
        auto Unite = [&](int from, int to) -> void {
            from = Find(Find, from);
            to = Find(Find, to);
            if (from != to) {
                fa[from] = to;
                --ans;
            }
        };
        auto id = [&](int i, int j) -> int { return i * n + j; };
        constexpr int di[] = {-1, 1, 0, 0}, dj[] = {0, 0, -1, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    ++ans;
                    int curr_id = id(i, j);
                    for (int d = 0; d < 4; d++) {
                        int ni = i + di[d], nj = j + dj[d];
                        if (ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] == '1') {
                            Unite(curr_id, id(ni, nj));
                        }
                    }
                }
            }
        }
        return ans;
    }
};
