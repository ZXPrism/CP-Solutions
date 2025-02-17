class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        int n = s.size();
        std::unordered_map<std::string, int> map;
        std::vector<int> cnt(26);
        int unique = 0;
        for (int i = 0; i < n; i++) {
            if (++cnt[s[i] - 'a'] == 1) {
                ++unique;
            }
            if (i >= minSize - 1) {
                if (unique <= maxLetters) {
                    ++map[s.substr(i - minSize + 1, minSize)];
                }
                if (--cnt[s[i - minSize + 1] - 'a'] == 0) {
                    --unique;
                }
            }
        }
        int ans = 0;
        for (auto &[str, cnt] : map) {
            ans = std::max(ans, cnt);
        }

        return ans;
    }
};
