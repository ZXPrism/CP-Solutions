class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        auto check = [&](long long x) -> bool {
            long long tot = 0;
            long long left = std::max(-1LL, index - (x - 1));
            long long right = std::min(1LL * n, index + (x - 1));
            long long xl = x - (index - left - 1), rl = x - (right - 1 - index);
            tot += (left + 1) + (n - right);
            tot += (xl + x) * (index - left) / 2;
            tot += (x - 1 + rl) * (right - index - 1) / 2;
            return tot <= maxSum;
        };
        int left = 0, right = maxSum + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
