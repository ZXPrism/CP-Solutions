class Solution {
public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0;
        std::unordered_map<int, int> cnt;
        for (int left = 0, right = 0; right < n; right++) {
            ++cnt[nums[right]];
            while (left <= right && cnt[nums[right]] > k) {
                --cnt[nums[left]];
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
