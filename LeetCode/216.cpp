class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        int sum = 0;
        auto dfs = [&](this auto &&dfs, int p) {
            if (sum > n || k - curr.size() > n - p + 1 || sum + (p + n) * (n - p + 1) / 2 < n) {
                return;
            }
            if (curr.size() == k) {
                if (sum == n) {
                    ans.push_back(curr);
                }
                return;
            }
            for (int i = p; i <= 9; i++) {
                curr.push_back(i);
                sum += i;
                dfs(i + 1);
                curr.pop_back();
                sum -= i;
            }
        };
        dfs(1);
        return ans;
    }
};
