class Solution {
public:
    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        std::vector<std::vector<int>> dp(numCarpets + 1, std::vector<int>(n));
        dp[0][0] = floor[0] - '0';
        for (int j = 1; j < n; j++) {
            dp[0][j] = dp[0][j - 1] + floor[j] - '0';
        }
        for (int i = 1; i <= numCarpets; i++) {
            for (int j = i * carpetLen; j < n; j++) {
                dp[i][j] = std::min(dp[i - 1][j - carpetLen], dp[i][j - 1] + floor[j] - '0');
            }
        }
        return dp[numCarpets][n - 1];
    }
};
