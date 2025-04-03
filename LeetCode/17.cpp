class Solution {
public:
    vector<string> letterCombinations(string digits) {
        std::vector<std::string> ans;
        std::string chmap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.size();
        if (n == 0) {
            return {};
        }
        std::string curr(n, '.');
        auto dfs = [&](this auto &&dfs, int k) {
            if (k == n) {
                ans.push_back(curr);
                return;
            }
            for (auto ch : chmap[digits[k] - '0']) {
                curr[k] = ch;
                dfs(k + 1);
            }
        };
        dfs(0);
        return ans;
    }
};
