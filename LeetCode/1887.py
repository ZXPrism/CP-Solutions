class Solution:
    def reductionOperations(self, nums: List[int]) -> int:
        nums.sort(reverse=True)
        n = len(nums)
        left = 0
        ans = 0
        curr = 0
        while left < n:
            right = left + 1
            while right < n and nums[left] == nums[right]:
                right += 1
            if right == n:
                break
            curr += right - left
            ans += curr
            left = right
        return ans
