class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        left, ans = 0, 0
        prod = 1
        for right, elem in enumerate(nums):
            prod *= elem
            while left <= right and prod >= k:
                prod //= nums[left]
                left += 1
            ans += right - left + 1
        return ans
