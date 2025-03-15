class Solution:
    def maxPower(self, s: str) -> int:
        n = len(s)
        left = 0
        ans = 0
        while left < n:
            right = left + 1
            while right < n and s[left] == s[right]:
                right += 1
            ans = max(ans, right - left)
            left = right
        return ans
