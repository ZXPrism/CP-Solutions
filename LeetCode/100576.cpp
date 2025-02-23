class Solution {
public:
    long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k) {
        int n = grid.size(), m = grid[0].size();
        std::priority_queue<int> q;
        for (int i = 0; i < n; i++) {
            std::ranges::sort(grid[i], std::greater<>());
            for (int j = 0; j < limits[i]; j++) {
                q.push(grid[i][j]);
            }
        }
        long long ans = 0;
        while (k--) {
            ans += q.top();
            q.pop();
        }
        return ans;
    }
};
