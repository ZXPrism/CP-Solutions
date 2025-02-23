class Solution {
public:
    long long minimumTime(vector<int> &time, int totalTrips) {
        auto check = [&](long long mid) -> bool {
            long long cnt = 0;
            for (auto t : time) {
                cnt += mid / t;
            }
            return cnt >= totalTrips;
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
