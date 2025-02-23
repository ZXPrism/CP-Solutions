class Solution {
public:
    int minSpeedOnTime(vector<int> &dist, double hour) {
        long long norm = static_cast<long long>(std::round(hour * 100));

        auto check = [&](int mid) -> bool {
            int n = dist.size();
            long long tot = 0;
            for (int i = 0; i < n - 1; i++) {
                tot += (dist[i] + mid - 1) / mid;
            }
            return 100 * (1LL * tot * mid + dist[n - 1]) <= 1LL * norm * mid;
        };
        int left = 0, right = 1'000'000'3, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return (right == 1'000'000'3 ? -1 : right);
    }
};
