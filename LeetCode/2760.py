class Solution:
    def longestAlternatingSubarray(self, nums: List[int], threshold: int) -> int:
        ans = 0
        left, n = 0, len(nums)
        while left < n:
            if nums[left] % 2 == 1 or nums[left] > threshold:
                left += 1
                continue
            right = left + 1
            while (
                right < n
                and nums[right] <= threshold
                and nums[right] % 2 != nums[right - 1] % 2
            ):
                right += 1
            ans = max(ans, right - left)
            left = right
        return ans
