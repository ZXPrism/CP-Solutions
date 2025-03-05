class Solution:
    def checkPartitioning(self, s: str) -> bool:
        n = len(s)
        dp = [[True] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]
        for i in range(n):
            for j in range(i + 1, n - 1):
                if dp[0][i] and dp[i + 1][j] and dp[j + 1][n - 1]:
                    return True
        return False
