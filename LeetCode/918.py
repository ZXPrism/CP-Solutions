class Solution:
    def maxSubarraySumCircular(self, nums: List[int]) -> int:
        dp_max = -0x3F3F3F3F
        curr_max = 0
        dp_min = 0x3F3F3F3F
        curr_min = 0
        s = 0
        for elem in nums:
            curr_max = max(curr_max, 0) + elem
            curr_min = min(curr_min, 0) + elem
            dp_max = max(dp_max, curr_max)
            dp_min = min(dp_min, curr_min)
            s += elem

        return dp_max if dp_min == s else max(dp_max, s - dp_min)
