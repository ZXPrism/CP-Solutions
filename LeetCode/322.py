class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n = len(coins)
        INF = int(1e5)
        dp = [INF] * (amount + 1)
        dp[0] = 0
        for i in range(n):
            for j in range(coins[i], amount + 1):
                dp[j] = min(dp[j], dp[j - coins[i]] + 1)
        return -1 if dp[amount] == INF else dp[amount]
