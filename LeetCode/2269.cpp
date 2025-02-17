class Solution {
public:
    int divisorSubstrings(int num, int k) {
        auto s = std::to_string(num);
        int n = s.size(), curr = 0, w = 1, ans = 0;
        for (int i = 1; i < k; i++) {
            w *= 10;
        }
        for (int i = 0; i < n; i++) {
            curr = curr * 10 + s[i] - '0';
            if (i >= k - 1) {
                if (curr && num % curr == 0) {
                    ++ans;
                }
                curr -= (s[i - k + 1] - '0') * w;
            }
        }
        return ans;
    }
};
