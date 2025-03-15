class Solution {
public:
    int scoreOfString(string s) {
        int n = s.size(), ans = 0;
        for (int i = 1; i < n; i++) {
            ans += std::abs(s[i - 1] - s[i]);
        }
        return ans;
    }
};
