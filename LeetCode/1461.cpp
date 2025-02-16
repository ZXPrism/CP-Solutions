class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        if (n < (1 << k) + k - 1) {
            return false;
        }

        int curr = 0;
        std::vector<int> check(1 << k);
        for (int i = 0; i < n; i++) {
            curr = (curr << 1) + s[i] - '0';
            if (i >= k - 1) {
                check[curr] = 1;
                curr -= (s[i - k + 1] - '0') << (k - 1);
            }
        }

        for (int i = 0; i < 1 << k; i++) {
            if (!check[i]) {
                return false;
            }
        }

        return true;
    }
};
