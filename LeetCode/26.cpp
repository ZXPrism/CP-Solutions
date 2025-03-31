class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        int n = nums.size(), k = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[k]) {
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
};
