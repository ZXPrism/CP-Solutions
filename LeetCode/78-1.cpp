class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size();
        std::vector<vector<int>> ans;
        std::vector<int> curr;
        auto dfs = [&](this auto &&dfs, int k) {
            ans.push_back(curr);
            if (k == n) {
                return;
            }
            for (int i = k; i < n; i++) {
                curr.push_back(nums[i]);
                dfs(i + 1);
                curr.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
