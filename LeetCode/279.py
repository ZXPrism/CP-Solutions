class Solution:
    def numSquares(self, n: int) -> int:
        nums = []
        for i in range(1, 101):
            if i * i > n:
                break
            nums.append(i * i)

        n_item = len(nums)
        INF = n + 1

        dp = [INF] * (n + 1)
        dp[0] = 0
        for i in range(n_item):
            for j in range(nums[i], n + 1):
                dp[j] = min(dp[j], dp[j - nums[i]] + 1)

        return dp[n]
