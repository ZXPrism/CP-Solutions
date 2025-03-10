class Solution:
    def countSubarrays(self, nums: List[int], k: int) -> int:
        max_elem = max(nums)
        cnt = 0
        left, ans = 0, 0
        for right, elem in enumerate(nums):
            if nums[right] == max_elem:
                cnt += 1
            while cnt >= k:
                if nums[left] == max_elem:
                    cnt -= 1
                left += 1
            ans += left
        return ans
