class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int> &nums, int k, int x) {
        int n = nums.size();
        std::vector<int> ans(n - k + 1);
        std::vector<int> cnt(50);
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                ++cnt[nums[i] + 50];
            }
            if (i >= k - 1) {
                for (int acc = 0, j = -50; j < 0; j++) {
                    if (acc + cnt[j + 50] >= x) {
                        ans[i - k + 1] = j;
                        break;
                    }
                    acc += cnt[j + 50];
                }
                if (nums[i - k + 1] < 0) {
                    --cnt[nums[i - k + 1] + 50];
                }
            }
        }
        return ans;
    }
};
