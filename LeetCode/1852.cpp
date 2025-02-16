class Solution {
public:
    vector<int> distinctNumbers(vector<int> &nums, int k) {
        int n = nums.size();
        std::vector<int> ans(n - k + 1);
        std::vector<int> cnt(*std::ranges::max_element(nums) + 1);
        for (int i = 0, unique = 0; i < n; i++) {
            if (++cnt[nums[i]] == 1) {
                ++unique;
            }
            if (i >= k - 1) {
                ans[i - k + 1] = unique;
                if (--cnt[nums[i - k + 1]] == 0) {
                    --unique;
                }
            }
        }

        return ans;
    }
};
