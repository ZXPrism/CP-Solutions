class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        s = sum(nums)
        if s % 2 == 1:
            return False
        target = s // 2
        dp = [False] * (target + 1)
        dp[0] = True
        for i in range(n):
            for j in range(target, nums[i] - 1, -1):
                dp[j] |= dp[j - nums[i]]
        return dp[target]
