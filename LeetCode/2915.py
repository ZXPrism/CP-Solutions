class Solution:
    def lengthOfLongestSubsequence(self, nums: List[int], target: int) -> int:
        INF = int(1e6)
        n = len(nums)
        dp = [-INF] * (target + 1)
        dp[0] = 0
        for i in range(n):
            for j in range(target, nums[i] - 1, -1):
                dp[j] = max(dp[j], dp[j - nums[i]] + 1)
        return -1 if dp[target] <= 0 else dp[target]
