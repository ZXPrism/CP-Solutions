class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
        int n = nums.size(), ans = 0;
        std::vector<int> cnt(101);
        for (int i = 0; i < n; i++) {
            ans += cnt[nums[i]]++;
        }
        return ans;
    }
};
