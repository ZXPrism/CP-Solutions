class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        one, zero = 0, 0
        left = 0
        n = len(s)
        while left < n:
            right = left + 1
            while right < n and s[left] == s[right]:
                right += 1
            if s[left] == "0":
                zero = max(zero, right - left)
            else:
                one = max(one, right - left)
            left = right
        return one > zero
