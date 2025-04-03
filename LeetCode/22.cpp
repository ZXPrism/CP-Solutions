class Solution {
public:
    vector<string> generateParenthesis(int n) {
        std::vector<std::string> ans;
        std::string curr;
        auto dfs = [&](this auto &&dfs, int left, int right) {
            if (right == 0) {
                ans.push_back(curr);
                return;
            }
            if (left) {
                curr.push_back('(');
                dfs(left - 1, right);
                curr.pop_back();
            }
            if (left < right) {
                curr.push_back(')');
                dfs(left, right - 1);
                curr.pop_back();
            }
        };
        dfs(n, n);
        return ans;
    }
};
