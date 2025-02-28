class Solution {
public:
    int splitArray(vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        auto check = [&](int limit) -> bool {
            int left = 0, cnt = 0;
            while (left < n) {
                int right = std::ranges::upper_bound(pre, pre[left] + limit) - pre.begin() - 1;
                ++cnt;
                left = right;
            }
            return cnt <= k;
        };
        int left = *std::ranges::max_element(nums) - 1, right = 1'000'000'001, mid = 0;
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
