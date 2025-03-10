class Solution:
    def palindromePartition(self, s: str, k: int) -> int:
        n = len(s)

        change = [[0] * n for _ in range(n)]
        for i in range(n - 1, -1, -1):
            for j in range(i + 1, n):
                change[i][j] = (s[i] != s[j]) + change[i + 1][j - 1]

        dp = [[n + 1] * (k + 1) for _ in range(n + 1)]
        dp[0][0] = 0

        for i in range(n):
            for j in range(1, k + 1):
                for p in range(i + 1):
                    dp[i + 1][j] = min(dp[i + 1][j], dp[p][j - 1] + change[p][i])

        return dp[n][k]
