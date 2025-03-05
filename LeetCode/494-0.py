class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        target += sum(nums)
        if target < 0 or target % 2 == 1:
            return 0
        target //= 2

        n = len(nums)
        dp = [[0] * (target + 1) for _ in range(n + 1)]
        dp[0][0] = 1

        for i in range(n):
            for j in range(target + 1):
                dp[i + 1][j] = dp[i][j]
                if j >= nums[i]:
                    dp[i + 1][j] += dp[i][j - nums[i]]

        return dp[n][target]
