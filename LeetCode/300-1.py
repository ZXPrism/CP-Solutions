class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n1 = len(nums)
        v = sorted(nums)
        v1 = []
        left = 0
        while left < n1:
            right = left + 1
            while right < n1 and v[left] == v[right]:
                right += 1
            v1.append(v[left])
            left = right
        n2 = len(v1)
        dp = [0] * (n2 + 1)
        for i in range(n1):
            t = 0
            for j in range(n2):
                tt = dp[j + 1]
                if nums[i] == v1[j]:
                    dp[j + 1] = t + 1
                else:
                    dp[j + 1] = max(dp[j + 1], dp[j])
                t = tt
        return dp[n2]
