class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        left, n = 0, len(s)
        ans = 0
        while left < n:
            right = left + 1
            while right < n and ord(s[right]) == ord(s[right - 1]) + 1:
                right += 1
            ans = max(ans, right - left)
            left = right
        return ans
