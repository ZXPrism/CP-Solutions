class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int ans = 0, n = nums.size();
        std::unordered_map<int, int> cnt;
        cnt[0] = 1;
        int pre = 0;
        for (int i = 0; i < n; i++) {
            pre += nums[i];
            ans += cnt[pre - k];
            ++cnt[pre];
        }
        return ans;
    }
};
