class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        n1 = len(nums1)
        n2 = len(nums2)
        dp = [-0x3F3F3F3F] * (n2 + 1)

        for i in range(n1):
            t = dp[0]
            for j in range(n2):
                tt = dp[j + 1]
                dp[j + 1] = max(
                    t + nums1[i] * nums2[j],
                    nums1[i] * nums2[j],
                    dp[j + 1],
                    dp[j],
                )
                t = tt

        return dp[n2]
