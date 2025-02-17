class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.size();
        std::vector<int> cnt(128);
        int fail = 0;
        for (int left = 0, right = 0; right < n; right++) {
            if (++cnt[s[right]] == 2) {
                ++fail;
            }
            while (left <= right && fail) {
                if (--cnt[s[left]] == 1) {
                    --fail;
                }
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
