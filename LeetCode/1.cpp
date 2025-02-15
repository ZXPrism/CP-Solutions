class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int n = nums.size();

        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::ranges::sort(idx, [&](int lhs, int rhs) { return nums[lhs] < nums[rhs]; });

        int left = 0, right = n - 1;
        while (left < right) {
            int sum = nums[idx[left]] + nums[idx[right]];
            if (sum == target) {
                return {idx[left], idx[right]};
            } else if (sum > target) {
                --right;
            } else {
                ++left;
            }
        }
        return {};
    }
};
