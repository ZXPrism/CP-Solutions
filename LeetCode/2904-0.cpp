class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        std::vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                pos.push_back(i);
            }
        }
        std::vector<std::string> ans;
        int n_pos = pos.size();
        for (int i = 0; i < n_pos; i++) {
            if (i >= k - 1) {
                int len = pos[i] - pos[i - k + 1] + 1;
                ans.push_back(s.substr(pos[i - k + 1], len));
            }
        }
        std::ranges::sort(ans, [&](auto &lhs, auto &rhs) {
            return lhs.size() == rhs.size() ? lhs < rhs : lhs.size() < rhs.size();
        });
        return (ans.empty() ? "" : ans.front());
    }
};
