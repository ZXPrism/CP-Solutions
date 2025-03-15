class Solution:
    def makeFancyString(self, s: str) -> str:
        n = len(s)
        left = 0
        ans = []
        while left < n:
            right = left + 1
            while right < n and s[right] == s[left]:
                right += 1
            ans.append(s[left : min(left + 2, right)])
            left = right
        return "".join(ans)
