# can be solved with grouped loop, but too trivial
# so I wrote a sliding window, bothersome but AC. enough. - 25.03.12


class Solution:
    def hasSpecialSubstring(self, s: str, k: int) -> bool:
        cnt = [0] * 27
        unique = 0
        n = len(s)
        for i, ch in enumerate(s):
            cnt[ord(ch) & 31] += 1
            if cnt[ord(ch) & 31] == 1:
                unique += 1
            if i >= k - 1:
                if (
                    unique == 1
                    and (i - k + 1 == 0 or s[i - k] != s[i])
                    and (i + 1 == n or s[i + 1] != s[i])
                ):
                    return True
                cnt[ord(s[i - k + 1]) & 31] -= 1
                if cnt[ord(s[i - k + 1]) & 31] == 0:
                    unique -= 1
        return False
