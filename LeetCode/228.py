class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        ans = []
        left = 0
        while left < n:
            right = left + 1
            while right < n and nums[right] - nums[right - 1] == 1:
                right = right + 1
            if right - left == 1:
                ans.append(f"{nums[left]}")
            else:
                ans.append(f"{nums[left]}->{nums[right - 1]}")
            left = right
        return ans
