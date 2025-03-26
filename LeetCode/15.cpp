class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        std::ranges::sort(nums);
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        int i = 0;
        while (i < n) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    int a = nums[left];
                    while (left < right && nums[left] == a) {
                        ++left;
                    }
                    int b = nums[right];
                    while (left < right && nums[right] == b) {
                        --right;
                    }
                } else if (sum > 0) {
                    --right;
                } else {
                    ++left;
                }
            }
            int curr = nums[i];
            while (i < n && nums[i] == curr) {
                ++i;
            }
        }
        return ans;
    }
};
