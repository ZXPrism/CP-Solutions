class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff) {
        int n = nums.size();
        std::multiset<int> s;
        for (int i = 0; i < n; i++) {
            int left = nums[i] - valueDiff, right = nums[i] + valueDiff;
            auto iter = s.lower_bound(left);
            if (iter != s.end() && *iter <= right) {
                return true;
            }
            s.insert(nums[i]);
            if (i >= indexDiff) {
                s.erase(s.find(nums[i - indexDiff]));
            }
        }
        return false;
    }
};
