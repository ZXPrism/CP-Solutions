class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size(), curr = 0, ans = 0;
        for (int left = 0, right = 0; right < n; right++) {
            curr += std::abs(s[right] - t[right]);
            while (left <= right && curr > maxCost) {
                curr -= std::abs(s[left] - t[left]);
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
