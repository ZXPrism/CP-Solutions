class Solution {
public:
    int shipWithinDays(vector<int> &weights, int days) {
        auto check = [&](int mid) -> bool {
            int cnt = 0, curr = 0;
            for (auto elem : weights) {
                curr += elem;
                if (curr > mid) {
                    curr = elem;
                    ++cnt;
                }
            }
            if (curr) {
                ++cnt;
            }
            return cnt <= days;
        };

        int left = *std::ranges::max_element(weights) - 1, right = 25000001, mid = 0;
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
