class Solution {
public:
    int minSwaps(vector<int> &nums) {
        int n = nums.size();
        int one = std::accumulate(nums.begin(), nums.end(), 0);
        if (one == 0) {
            return 0;
        }

        nums.resize(2 * n);
        for (int i = 0; i < n; i++) {
            nums[i + n] = nums[i];
        }

        int ans = one, zero = 0;
        for (int i = 0; i < 2 * n; i++) {
            zero += 1 - nums[i];
            if (i >= one - 1) {
                ans = std::min(ans, zero);
                zero -= 1 - nums[i - one + 1];
            }
        }
        return ans;
    }
};
