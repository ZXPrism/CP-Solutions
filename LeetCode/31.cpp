class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int n = nums.size();
        int j = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                j = i;
                break;
            }
        }
        if (j != -1) {
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[j]) {
                    std::swap(nums[i], nums[j]);
                    break;
                }
            }
        }
        std::reverse(nums.begin() + j + 1, nums.end());
    }
};
