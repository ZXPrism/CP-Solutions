class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int> &nums) {
        std::ranges::sort(nums);
        // iff is so powerful!
        int n = nums.size();
        unsigned max_elem = nums.back();
        std::vector<int> dp(n, 1);
        std::vector<int> from(n, -1);
        std::vector<int> valid_index;
        int max_len = 1, right = 0;
        for (int i = 0; i < n; i++) {
            for (auto j : valid_index) {
                if (nums[i] % nums[j] == 0) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        from[i] = j;
                    }
                }
            }
            if (dp[i] > max_len) {
                max_len = dp[i];
                right = i;
                std::vector<int> new_valid_index;
                for (auto j : valid_index) {
                    if (dp[j] + std::bit_width(max_elem / nums[j]) - 1 > max_len) {
                        new_valid_index.push_back(j);
                    }
                }
                valid_index.swap(new_valid_index);
            }
            if (dp[i] + std::bit_width(max_elem / nums[i]) - 1 > max_len) {
                valid_index.push_back(i);
            }
        }

        std::vector<int> ans;
        while (right != -1) {
            ans.push_back(nums[right]);
            right = from[right];
        }
        return ans;
    }
};
