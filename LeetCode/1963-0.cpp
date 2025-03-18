class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        auto check = [&](int t) -> bool {
            std::string ss = s;
            int left = 0, right = n - 1;
            while (t && left < right) {
                if (ss[left] == '[') {
                    ++left;
                } else if (ss[right] == ']') {
                    --right;
                } else {
                    std::swap(ss[left], ss[right]);
                    ++left;
                    --right;
                    --t;
                }
            }
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (ss[i] == '[') {
                    ++cnt;
                }
                if (cnt < i + 1 - cnt) {
                    return false;
                }
            }
            return true;
        };
        int left = -1, right = n / 2 + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
