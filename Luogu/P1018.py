import sys, heapq
from bisect import *
from collections import deque, defaultdict

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())

    num = input().strip()

    val = [[0] * n for _ in range(n)]
    for i in range(n):
        val[i][i] = int(num[i])
        for j in range(i + 1, n):
            val[i][j] = val[i][j - 1] * 10 + int(num[j])

    dp = [[0] * (n + 1) for _ in range(k + 2)]
    for i in range(n):
        dp[1][i + 1] = val[0][i]

    for i in range(n):
        for j in range(2, k + 2):
            for m in range(i):
                dp[j][i + 1] = max(dp[j][i + 1], dp[j - 1][m + 1] * val[m + 1][i])

    print(dp[k + 1][n])


t = 1
for _ in range(t):
    solve()
