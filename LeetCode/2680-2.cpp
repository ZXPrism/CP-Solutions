class Solution {
public:
    long long maximumOr(vector<int> &nums, int k) {
        long long ans = 0;
        int tot = 0, correction = 0;
        for (auto elem : nums) {
            correction |= tot & elem;
            tot |= elem;
        }
        for (auto elem : nums) {
            ans = std::max(ans, (1LL * elem << k) | (tot ^ elem) | correction);
        }
        return ans;
    }
};
