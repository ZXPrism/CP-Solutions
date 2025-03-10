class Solution:
    def numberOfSubstrings(self, s: str, k: int) -> int:
        ans = 0
        cnt = [0] * 27
        left, ans = 0, 0
        for right, elem in enumerate(s):
            cnt[ord(s[right]) & 31] += 1
            while cnt[ord(s[right]) & 31] >= k:
                cnt[ord(s[left]) & 31] -= 1
                left += 1
            ans += left
        return ans
