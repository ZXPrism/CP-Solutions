class Solution {
public:
    long long beautifulSubarrays(vector<int> &nums) {
        long long ans = 0;
        int n = nums.size();
        int pattern = 0;
        std::vector<int> cnt((*std::ranges::max_element(nums) << 1) + 1);
        cnt[0] = 1;
        for (int i = 0; i < n; i++) {
            pattern ^= nums[i];
            ans += cnt[pattern];
            ++cnt[pattern];
        }
        return ans;
    }
};
