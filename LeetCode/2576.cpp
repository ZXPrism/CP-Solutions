class Solution {
public:
    int maxNumOfMarkedIndices(vector<int> &nums) {
        int n = nums.size();
        std::ranges::sort(nums);

        auto check = [&](int cnt) -> bool {
            for (int i = 0; i < cnt; i++) {
                if (2 * nums[i] > nums[n - cnt + i]) {
                    return false;
                }
            }
            return true;
        };

        int left = 0, right = n / 2 + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }

        return left * 2;
    }
};
