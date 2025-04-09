class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        int n = nums.size();
        std::vector<int> suf_distinct(n);
        std::vector<int> cnt(101);
        int distinct = 0;
        for (int i = n - 1; i >= 0; i--) {
            distinct += (++cnt[nums[i]] == 1);
            suf_distinct[i] = distinct;
        }
        for (int i = 0; i < n; i += 3) {
            if (suf_distinct[i] == n - i) {
                return i / 3;
            }
        }
        return (n + 2) / 3;
    }
};
