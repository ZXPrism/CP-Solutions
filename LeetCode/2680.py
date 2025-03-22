class Solution:
    def maximumOr(self, nums: List[int], k: int) -> int:
        tot = 0
        always = 0
        for elem in nums:
            always |= elem & tot
            tot |= elem
        ans = 0
        for elem in nums:
            ans = max(ans, (tot ^ elem) | always | (elem << k))
        return ans
