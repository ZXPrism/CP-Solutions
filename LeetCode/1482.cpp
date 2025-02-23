class Solution {
public:
    int minDays(vector<int> &bloomDay, int m, int k) {
        auto check = [&](int day) -> bool {
            int n = bloomDay.size(), tot = 0;
            for (int left = 0; left < n;) {
                if (bloomDay[left] > day) {
                    ++left;
                    continue;
                }
                int right = left + 1;
                while (right < n && bloomDay[right] <= day) {
                    ++right;
                }
                tot += (right - left) / k;
                left = right;
            }
            return tot >= m;
        };
        int R = *std::ranges::max_element(bloomDay) + 1;
        int left = 0, right = R, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return (right == R ? -1 : right);
    }
};
