class Solution {
public:
    int minSwaps(string s) {
        int cnt = 0, ans = 0, n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == '[') {
                ++cnt;
            } else if (i + 1 - cnt > cnt) {
                ++cnt;
                ++ans;
            }
        }
        return ans;
    }
};
