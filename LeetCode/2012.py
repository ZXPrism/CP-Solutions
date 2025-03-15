class Solution:
    def sumOfBeauties(self, nums: List[int]) -> int:
        n = len(nums)
        pre_max = [0] * (n + 1)
        suf_min = [1000000] * (n + 2)
        for i in range(n):
            pre_max[i + 1] = max(pre_max[i], nums[i])
        for i in range(n - 1, -1, -1):
            suf_min[i + 1] = min(suf_min[i + 2], nums[i])
        ans = 0
        for i in range(1, n - 1):
            if nums[i] > pre_max[i] and nums[i] < suf_min[i + 2]:
                ans += 2
            elif nums[i - 1] < nums[i] < nums[i + 1]:
                ans += 1
        return ans
