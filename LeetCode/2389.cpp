class Solution {
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
        int n = nums.size(), m = queries.size();
        std::ranges::sort(nums);
        std::vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        std::vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            ans[i] = std::ranges::upper_bound(pre, queries[i]) - pre.begin() - 1;
        }
        return ans;
    }
};
