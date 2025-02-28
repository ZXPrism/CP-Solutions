class Solution {
public:
    int maxPossibleScore(vector<int> &start, int d) {
        std::ranges::sort(start);
        auto check = [&](long long delta) -> bool {
            long long prev = start.front() - delta;
            for (auto elem : start) {
                if (prev + delta > elem + d) {
                    return false;
                }
                prev = std::max(1LL * elem, prev + delta);
            }
            return true;
        };
        long long left = -1, right = 2'000'000'001, mid = 0;
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
