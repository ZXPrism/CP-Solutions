class Solution {
public:
    int minimumSize(vector<int> &nums, int maxOperations) {
        int n = nums.size();
        int left = 0, right = 1'000'000'001, mid = 0;
        auto check = [&](int limit) -> bool {
            long long tot = 0;
            for (auto elem : nums) {
                tot += (elem + limit - 1) / limit;
            }
            return tot - n <= maxOperations;
        };
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
