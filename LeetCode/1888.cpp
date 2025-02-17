class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s.resize(2 * n);
        for (int i = 0; i < n; i++) {
            s[i + n] = s[i];
        }

        int ans = n, match = 0;
        for (int i = 0, x = 0; i < 2 * n; i++, x ^= 1) {
            if (s[i] == '0' + x) {
                ++match;
            }
            if (i >= n - 1) {
                ans = std::min(ans, std::min(match, n - match));
                if (s[i - n + 1] == '0' + (x ^ (n % 2 == 0))) {
                    --match;
                }
            }
        }

        return ans;
    }
};
