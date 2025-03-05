class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()

        def check(val: int) -> bool:
            cnt = 0
            for i in range(n):
                cnt += bisect_right(nums, nums[i] + val, i + 1) - i - 1
            return cnt >= k

        left, right, mid = -1, int(1e6) + 1, 0
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid

        return right
