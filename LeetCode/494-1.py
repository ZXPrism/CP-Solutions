class Solution:
    def findTargetSumWays(self, nums: List[int], target: int) -> int:
        target += sum(nums)
        if target < 0 or target % 2 == 1:
            return 0
        target //= 2

        n = len(nums)
        dp = [0] * (target + 1)
        dp[0] = 1

        for i in range(n):
            for j in range(target, nums[i] - 1, -1):
                dp[j] += dp[j - nums[i]]

        return dp[target]
