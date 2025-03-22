class Solution {
public:
    int maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        std::vector<int> dp(n2 + 1);
        for (int i = 0; i < n1; i++) {
            int t = dp[0];
            for (int j = 0; j < n2; j++) {
                int tt = dp[j + 1];
                if (nums1[i] == nums2[j]) {
                    dp[j + 1] = t + 1;
                } else {
                    dp[j + 1] = std::max(dp[j], dp[j + 1]);
                }
                t = tt;
            }
        }
        return dp[n2];
    }
};
