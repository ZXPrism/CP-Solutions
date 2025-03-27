class Solution {
public:
    int threeSumSmaller(vector<int> &nums, int target) {
        std::ranges::sort(nums);
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum < target) {
                    ans += right - left;
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
};
