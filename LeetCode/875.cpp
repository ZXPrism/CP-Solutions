class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        auto check = [&](int mid) -> bool {
            long long req = 0;
            for (auto elem : piles) {
                req += (elem + mid - 1) / mid;
            }
            return req <= h;
        };
        int left = 0, right = *std::ranges::max_element(piles) + 1, mid = 0;
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
