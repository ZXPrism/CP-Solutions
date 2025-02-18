class Solution {
public:
    int search(vector<int> &nums, int target) {
        int x = std::ranges::lower_bound(nums, target) - nums.begin(), n = nums.size();
        return (x != n && nums[x] == target ? x : -1);
    }
};
