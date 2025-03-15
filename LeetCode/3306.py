class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        target = set(["a", "e", "i", "o", "u"])

        ans_g = 0
        cnt = [0] * 27
        cnt_conso = 0
        diff = 5

        left = 0
        for right, ch in enumerate(word):
            if ch not in target:
                cnt_conso += 1
            else:
                cnt[ord(ch) & 31] += 1
                if cnt[ord(ch) & 31] == 1:
                    diff -= 1
            while diff == 0 and cnt_conso > k:
                if word[left] not in target:
                    cnt_conso -= 1
                else:
                    cnt[ord(word[left]) & 31] -= 1
                    if cnt[ord(word[left]) & 31] == 0:
                        diff += 1
                left += 1
            ans_g += left

        ans_ge = 0
        cnt = [0] * 27
        cnt_conso = 0
        diff = 5

        left = 0
        for right, ch in enumerate(word):
            if ch not in target:
                cnt_conso += 1
            else:
                cnt[ord(ch) & 31] += 1
                if cnt[ord(ch) & 31] == 1:
                    diff -= 1
            while diff == 0 and cnt_conso >= k:
                if word[left] not in target:
                    cnt_conso -= 1
                else:
                    cnt[ord(word[left]) & 31] -= 1
                    if cnt[ord(word[left]) & 31] == 0:
                        diff += 1
                left += 1
            ans_ge += left

        return ans_ge - ans_g
