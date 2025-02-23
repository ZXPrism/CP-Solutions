class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int> &workerTimes) {
        auto f = [&](int power, long long t) -> int {
            long long left = 0, right = std::sqrt(2 * t) + 1, mid = 0;
            while (left + 1 < right) {
                mid = (left + right) / 2;
                if (mid * (mid + 1) <= 2 * t / power) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            return left;
        };

        auto check = [&](long long t) -> bool {
            long long tot = 0;
            for (auto elem : workerTimes) {
                tot += f(elem, t);
            }
            return tot >= mountainHeight;
        };
        long long left = 0, right = static_cast<long long>(1e16), mid = 0;
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
