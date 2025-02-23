class Solution {
public:
    int maximumCandies(vector<int> &candies, long long k) {
        auto check = [&](int mid) -> bool {
            long long tot = 0;
            for (auto elem : candies) {
                tot += elem / mid;
            }
            return tot >= k;
        };
        int left = 0, right = *std::ranges::max_element(candies) + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) >> 1;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
