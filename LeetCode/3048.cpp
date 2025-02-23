class Solution {
public:
    int earliestSecondToMarkIndices(vector<int> &nums, vector<int> &changeIndices) {
        int n = nums.size(), m = changeIndices.size();
        auto check = [&](int sec) -> bool {
            std::vector<int> has(n + 1), need;
            for (int i = sec - 1, cnt = 0; i >= 0; i--) {
                if (++has[changeIndices[i]] == 1) {
                    need.push_back(i);
                    if (need.size() == n) {
                        break;
                    }
                }
            }
            if (need.size() == n) {
                long long used = 0;
                for (int i = n - 1; i >= 0; i--) {
                    if (need[i] - (used + (n - 1 - i)) < nums[changeIndices[need[i]] - 1]) {
                        return false;
                    }
                    used += nums[changeIndices[need[i]] - 1];
                }
                return true;
            } else {
                return false;
            }
        };
        int left = 0, right = m + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return (right == m + 1 ? -1 : right);
    }
};
