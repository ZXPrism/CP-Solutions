class Solution {
public:
    int numKLenSubstrNoRepeats(string s, int k) {
        int n = s.size(), ans = 0;
        std::vector<int> cnt(26);
        int unique_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (++cnt[s[i] - 'a'] == 1) {
                ++unique_cnt;
            }
            if (i >= k - 1) {
                if (unique_cnt == k) {
                    ++ans;
                }
                if (--cnt[s[i - k + 1] - 'a'] == 0) {
                    --unique_cnt;
                }
            }
        }
        return ans;
    }
};
