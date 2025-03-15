class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        n = len(nums)
        left = 0
        ans = 0
        while left < n:
            right = left + 1
            while right < n and nums[right] > nums[right - 1]:
                right += 1
            ans = max(ans, right - left)
            left = right
        return ans
