class Solution {
public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size() - 1;
        for (int i = 0; i <= n; i++) {
            while (nums[nums[i] - 1] != nums[i]) {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        return nums[n];
    }
};
