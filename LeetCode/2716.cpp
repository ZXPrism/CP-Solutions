class Solution {
public:
    int minimizedStringLength(string s) {
        std::vector<int> cnt(26);
        int ans = 0;
        for (auto ch : s) {
            ans += (++cnt[ch - 'a'] == 1);
        }
        return ans;
    }
};
