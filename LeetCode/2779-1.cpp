class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        int max_val = *std::ranges::max_element(nums);
        std::vector<int> cnt(max_val + 1);
        int min_val = 100001;
        for (auto elem : nums) {
            ++cnt[elem];
            min_val = std::min(min_val, elem);
        }
        int ans = 0, curr = 0;
        for (int i = min_val; i <= max_val; i++) {
            curr += cnt[i];
            ans = std::max(ans, curr);
            if (i - min_val >= 2 * k) {
                curr -= cnt[i - 2 * k];
            }
        }
        return ans;
    }
};
