class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::vector<std::vector<int>> ans;
        int n = candidates.size();
        std::vector<int> curr;
        int sum = 0;
        auto dfs = [&](this auto &&dfs, int k) {
            if (sum >= target) {
                if (sum == target) {
                    ans.push_back(curr);
                }
                return;
            }

            for (int i = k; i < n; i++) {
                sum += candidates[i];
                curr.push_back(candidates[i]);
                dfs(i);
                curr.pop_back();
                sum -= candidates[i];
            }
        };
        dfs(0);
        return ans;
    }
};
