class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        left = 0
        cnt = [0] * 3
        ans = 0
        for right in range(n):
            cnt[ord(s[right]) - ord("a")] += 1
            while cnt[0] >= 1 and cnt[1] >= 1 and cnt[2] >= 1:
                cnt[ord(s[left]) - ord("a")] -= 1
                left += 1
            ans += left
        return ans
