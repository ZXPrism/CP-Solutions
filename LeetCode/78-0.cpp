class Solution {
public:
    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size();
        std::vector<vector<int>> ans;
        std::vector<int> curr;
        auto dfs = [&](this auto &&dfs, int i) {
            if (i == n) {
                ans.push_back(curr);
                return;
            }
            curr.push_back(nums[i]);
            dfs(i + 1);
            curr.pop_back();
            dfs(i + 1);
        };
        dfs(0);
        return ans;
    }
};
