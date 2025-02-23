class Solution {
public:
    long long repairCars(vector<int> &ranks, int cars) {
        auto check = [&](long long x) -> bool {
            long long tot = 0;
            for (auto rank : ranks) {
                tot += static_cast<int>(std::sqrt(x / rank));
            }
            return tot >= cars;
        };
        long long left = 0, right = static_cast<long long>(1e14) + 1, mid = 0;
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
