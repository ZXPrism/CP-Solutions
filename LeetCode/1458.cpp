class Solution {
public:
    int maxDotProduct(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();

        constexpr int INF = 0x3f3f3f3f;
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1, -INF));
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                dp[i + 1][j + 1] =
                    std::max({nums1[i] * nums2[j], dp[i + 1][j], dp[i][j + 1],
                              (dp[i][j] == -INF ? 0 : dp[i][j]) + nums1[i] * nums2[j]});
            }
        }

        return dp[n1][n2];
    }
};
