class Solution {
public:
    bool queryString(string s, int n) {
        int str_n = s.size();
        int msb = 31 - __builtin_clz(n);

        if (n == 1) {
            return s.find('1') != std::string::npos;
        }

        if ((1 << (msb - 1)) + msb - 1 > str_n) {
            return false;
        }

        auto check = [&](int len, int left, int right) -> bool {
            int curr = 0;
            std::set<int> set;
            for (int i = 0; i < str_n; i++) {
                curr = curr * 2 + s[i] - '0';
                if (i >= len - 1) {
                    if (curr >= left && curr <= right) {
                        set.insert(curr);
                    }
                    curr -= (s[i - len + 1] - '0') << (len - 1);
                }
            }
            return set.size() == right - left + 1;
        };

        return check(msb, 1 << (msb - 1), (1 << msb) - 1) && check(msb + 1, 1 << msb, n);
    }
};
