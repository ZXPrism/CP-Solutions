class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::ranges::sort(nums);
        int n = nums.size();
        int ans = 666, min_dist = 100000;
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int s = nums[i] + nums[left] + nums[right];
                if (s >= target) {
                    if (s - target < min_dist) {
                        ans = s;
                        min_dist = s - target;
                    }
                    --right;
                } else {
                    if (target - s < min_dist) {
                        ans = s;
                        min_dist = target - s;
                    }
                    ++left;
                }
            }
        }
        return ans;
    }
};
