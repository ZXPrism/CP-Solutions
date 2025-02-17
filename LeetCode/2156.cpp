class Solution {
public:
    string subStrHash(string s, int power, int modulo, int k, int hashValue) {
        long long hash = 0;
        int n = s.size(), ans = 0;
        long long w = 1;

        for (int i = 1; i < k; i++) {
            w = (w * power) % modulo;
        }

        for (int i = n - 1; i >= 0; i--) {
            hash = (hash * power + (s[i] & 31)) % modulo;
            if (n - 1 - i >= k - 1) {
                if (hash == hashValue) {
                    ans = i;
                }
                hash = (hash - 1LL * (s[i + k - 1] & 31) * w + 26LL * modulo) % modulo;
            }
        }

        return s.substr(ans, k);
    }
};
