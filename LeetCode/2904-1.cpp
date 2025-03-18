class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int left = 0, curr = 0, len = n + 1;
        for (int right = 0; right < n; right++) {
            curr += s[right] - '0';
            while (curr >= k) {
                curr -= s[left++] - '0';
            }
            if (left != 0) {
                len = std::min(len, right - left + 2);
            }
        }
        if (len == n + 1) {
            return "";
        }
        curr = 0;
        std::vector<std::string> ans;
        for (int i = 0; i < n; i++) {
            curr += s[i] - '0';
            if (i >= len - 1) {
                if (curr == k) {
                    ans.push_back(s.substr(i - len + 1, len));
                }
                curr -= s[i - len + 1] - '0';
            }
        }
        std::ranges::sort(ans, [&](auto &lhs, auto &rhs) { return lhs < rhs; });
        return ans[0];
    }
};
