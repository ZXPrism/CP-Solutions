class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size(), ans = 0;

        std::vector<int> orig(26);
        for (auto ch : s) {
            ++orig[ch - 'a'];
        }

        for (int i = 0; i < 3; i++) {
            if (orig[i] < k) {
                return -1;
            }
        }

        std::vector<int> cnt(26);
        for (int left = 0, right = 0; right < n; right++) {
            ++cnt[s[right] - 'a'];
            while (left <= right && orig[s[right] - 'a'] - cnt[s[right] - 'a'] < k) {
                --cnt[s[left] - 'a'];
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }

        return n - ans;
    }
};
