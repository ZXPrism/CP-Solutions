class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size(), ans = 0;
        std::vector<int> cnt(26);
        for (int left = 0, right = 0; right < n; right++) {
            ++cnt[s[right] - 'a'];
            while (left <= right && cnt[s[right] - 'a'] == 3) {
                --cnt[s[left] - 'a'];
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
