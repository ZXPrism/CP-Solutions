class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff) {
        for (int i = 1; i < indexDiff; i++) {
            nums.push_back(std::numeric_limits<int>::max());
        }
        int n = nums.size();

        std::multiset<int> s;
        for (int i = 0; i < n; i++) {
            s.insert(nums[i]);
            if (i >= indexDiff) {
                s.erase(s.find(nums[i - indexDiff]));
                int left = nums[i - indexDiff] - valueDiff, right = nums[i - indexDiff] + valueDiff;
                auto iter = s.lower_bound(left);
                if (iter != s.end() && *iter <= right) {
                    return true;
                }
            }
        }

        return false;
    }
};
