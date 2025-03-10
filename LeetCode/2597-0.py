class Solution:
    def beautifulSubsets(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        ans = 0
        for i in range(1, 1 << n):
            curr = []
            for j in range(n):
                if i >> j & 1:
                    curr.append(nums[j])
            n_curr = len(curr)
            flag = True
            for j in range(n_curr):
                idx = bisect_left(curr, curr[j] + k)
                if idx != n_curr and curr[idx] == curr[j] + k:
                    flag = False
                    break
            if flag:
                ans += 1
        return ans
