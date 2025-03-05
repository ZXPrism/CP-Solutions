class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int lcm = std::lcm(a, b);
        long long left = std::min(a, b) - 1, right = static_cast<long long>(1e14), mid = 0;
        auto check = [&](long long val) -> bool { return val / a + val / b - val / lcm >= n; };
        while (left + 1 < right) {
            mid = (left + right) >> 1;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right % 1000000007;
    }
};
