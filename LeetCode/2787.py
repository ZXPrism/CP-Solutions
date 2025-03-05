class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        MOD = 1000000007

        nums = []
        i = 1
        while i**x <= n:
            nums.append(i**x)
            i += 1
        k = len(nums)

        dp = [0] * (n + 1)
        dp[0] = 1
        for i in range(k):
            for j in range(n, nums[i] - 1, -1):
                dp[j] = (dp[j] + dp[j - nums[i]]) % MOD

        return dp[n]
