class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        n = len(nums)
        nums.sort()

        def check(val: int) -> bool:
            cnt = 0
            left = 0
            for right in range(n):
                while nums[right] - nums[left] > val:
                    left += 1
                cnt += right - left
            return cnt >= k

        left, right, mid = -1, int(1e6) + 1, 0
        while left + 1 < right:
            mid = (left + right) // 2
            if check(mid):
                right = mid
            else:
                left = mid

        return right
