class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        f = []
        for i, elem in enumerate(nums):
            k = bisect_left(f, elem)
            if k == len(f):
                f.append(elem)
            else:
                f[k] = elem

        return len(f)
