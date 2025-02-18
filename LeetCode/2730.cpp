class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size(), ans = 0, cnt = 0;
        for (int left = 0, right = 0; right < n; right++) {
            if (left < right && s[right] == s[right - 1]) {
                ++cnt;
            }
            while (left <= right && cnt == 2) {
                if (s[left] == s[left + 1]) {
                    --cnt;
                }
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
