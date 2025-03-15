class Solution:
    def evenProduct(self, nums: List[int]) -> int:
        ans, left = 0, 0
        for right, elem in enumerate(nums):
            if elem % 2 == 0:
                left = right + 1
            ans += left
        return ans
