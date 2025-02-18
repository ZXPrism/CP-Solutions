class Solution {
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success) {
        std::ranges::sort(potions);
        int n = spells.size(), m = potions.size();
        std::vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int left = -1, right = m, mid = 0;
            while (left + 1 < right) {
                mid = (left + right) / 2;
                if (1LL * spells[i] * potions[mid] >= success) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            ans[i] = m - right;
        }
        return ans;
    }
};
