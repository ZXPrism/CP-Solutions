class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        auto check = [&](int val) -> bool {
            int cnt = 0;
            for (int i = 1; i <= m; i++) {
                cnt += std::min(n, val / i);
            }
            return cnt >= k;
        };
        int left = 0, right = m * n + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
