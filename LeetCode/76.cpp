class Solution {
public:
    string minWindow(string s, string t) {
        std::vector<int> pattern(128);
        for (auto ch : t) {
            ++pattern[ch];
        }
        int n = s.size(), diff = t.size();
        std::vector<int> cnt(128);
        int ans = n + 1, start = -1;
        for (int left = 0, right = 0; right < n; right++) {
            diff -= (++cnt[s[right]] <= pattern[s[right]]);
            while (diff == 0) {
                if (right - left + 1 < ans) {
                    ans = right - left + 1;
                    start = left;
                }
                diff += (--cnt[s[left]] < pattern[s[left]]);
                ++left;
            }
        }
        return (start == -1 ? "" : s.substr(start, ans));
    }
};
