class Solution {
public:
    int maximumUniqueSubarray(vector<int> &nums) {
        int n = nums.size(), ans = 0, curr = 0;
        std::vector<int> cnt(10001);
        for (int left = 0, right = 0; right < n; right++) {
            curr += nums[right];
            ++cnt[nums[right]];
            while (left <= right && cnt[nums[right]] == 2) {
                curr -= nums[left];
                --cnt[nums[left]];
                ++left;
            }
            ans = std::max(ans, curr);
        }
        return ans;
    }
};
