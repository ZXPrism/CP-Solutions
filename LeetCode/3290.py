class Solution:
    def maxScore(self, a: List[int], b: List[int]) -> int:
        n = len(b)
        INF = int(1e15)
        dp = [-INF] * 5
        dp[0] = 0
        for i in range(n):
            for j in range(3, -1, -1):
                dp[j + 1] = max(dp[j + 1], dp[j] + a[j] * b[i])
        return dp[4]
