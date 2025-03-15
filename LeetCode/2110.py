class Solution:
    def getDescentPeriods(self, prices: List[int]) -> int:
        n = len(prices)
        left, ans = 0, 0
        while left < n:
            right = left + 1
            while right < n and prices[right] == prices[right - 1] - 1:
                right += 1
            x = right - left
            ans += x * (1 + x) // 2
            left = right
        return ans
