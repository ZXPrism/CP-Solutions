class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        int n = nums.size(), len = k + 1;
        std::unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            if (cnt[nums[i]]++ >= 1) {
                return true;
            }
            if (i >= len - 1) {
                --cnt[nums[i - len + 1]];
            }
        }
        return false;
    }
};
