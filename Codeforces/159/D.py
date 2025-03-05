import sys
from bisect import *

input = sys.stdin.readline


def solve():
    s = input().strip()
    n = len(s)

    cnt = [1] * n
    dp = [[True] * n for _ in range(n)]
    for i in range(n - 1, -1, -1):
        for j in range(i + 1, n):
            dp[i][j] = (s[i] == s[j]) and dp[i + 1][j - 1]
            if dp[i][j] == True:
                cnt[i] += 1

    suf = [0] * (n + 2)
    for i in range(n - 1, -1, -1):
        suf[i + 1] = suf[i + 2] + cnt[i]

    ans = 0
    for i in range(n):
        for j in range(i, n):
            if dp[i][j]:
                ans += suf[j + 2]

    print(ans)


solve()
