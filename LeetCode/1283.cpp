class Solution {
public:
    int smallestDivisor(vector<int> &nums, int threshold) {
        int n = nums.size();

        auto check = [&](int mid) -> bool {
            long long tot = 0;
            for (int i = 0; i < n; i++) {
                tot += (nums[i] + mid - 1) / mid;
            }
            return tot <= threshold;
        };

        int left = 0, right = *std::ranges::max_element(nums) + 1, mid = 0;
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
