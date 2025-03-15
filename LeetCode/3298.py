class Solution:
    def validSubstringCount(self, word1: str, word2: str) -> int:
        pattern = [0] * 27
        diff = 0
        for ch in word2:
            pattern[ord(ch) & 31] += 1
            diff += 1

        ans, left = 0, 0
        cnt = [0] * 27
        for right, ch in enumerate(word1):
            curr = ord(ch) & 31
            cnt[curr] += 1
            if cnt[curr] <= pattern[curr]:
                diff -= 1
            while diff == 0:
                curr = ord(word1[left]) & 31
                cnt[curr] -= 1
                if cnt[curr] < pattern[curr]:
                    diff += 1
                left += 1
            ans += left

        return ans
