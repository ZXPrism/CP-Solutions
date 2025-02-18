class Solution {
public:
    int totalFruit(vector<int> &fruits) {
        int n = fruits.size(), ans = 0, check = 0;
        std::vector<int> cnt(n);
        for (int left = 0, right = 0; right < n; right++) {
            if (++cnt[fruits[right]] == 1) {
                ++check;
            }
            while (left <= right && check > 2) {
                if (--cnt[fruits[left]] == 0) {
                    --check;
                }
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
