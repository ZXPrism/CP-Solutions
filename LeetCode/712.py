class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n1 = len(s1)
        n2 = len(s2)
        dp = [0] * (n2 + 1)
        for i in range(n2):
            dp[i + 1] = dp[i] + ord(s2[i])
        for i in range(n1):
            t = dp[0]
            dp[0] += ord(s1[i])
            for j in range(n2):
                tt = dp[j + 1]
                if s1[i] == s2[j]:
                    dp[j + 1] = t
                else:
                    dp[j + 1] = min(dp[j] + ord(s2[j]), dp[j + 1] + ord(s1[i]))
                t = tt
        return dp[n2]
