class Solution:
    def countKConstraintSubstrings(self, s: str, k: int) -> int:
        left = 0
        ans = 0
        zero = 0
        for right, ch in enumerate(s):
            if ch == "0":
                zero += 1
            while zero > k and right - left + 1 - zero > k:
                if s[left] == "0":
                    zero -= 1
                left += 1
            ans += right - left + 1
        return ans
