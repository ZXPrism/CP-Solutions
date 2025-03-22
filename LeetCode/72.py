class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        n1 = len(word1)
        n2 = len(word2)
        dp = [i for i in range(n2 + 1)]
        for i in range(n1):
            t = dp[0]
            dp[0] = i + 1
            for j in range(n2):
                tt = dp[j + 1]
                if word1[i] == word2[j]:
                    dp[j + 1] = t
                else:
                    dp[j + 1] = min(dp[j], dp[j + 1], t) + 1
                t = tt
        return dp[n2]
