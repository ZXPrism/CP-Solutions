class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        std::vector<std::vector<int>> ok(n);
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                auto curr = s.substr(i, j - i + 1);
                auto rev = curr;
                std::reverse(rev.begin(), rev.end());
                if (curr == rev) {
                    ok[i].push_back(j);
                }
            }
        }
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> curr;
        auto dfs = [&](this auto &&dfs, int left) -> void {
            if (left == n) {
                ans.push_back(curr);
                return;
            }
            for (auto right : ok[left]) {
                curr.push_back(s.substr(left, right - left + 1));
                dfs(right + 1);
                curr.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};
