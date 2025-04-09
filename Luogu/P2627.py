import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    v = [int(input()) for _ in range(n)]

    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + v[i]

    dp = [0] * (n + 2)
    maxq = deque()
    for i in range(n + 1):
        dp[i + 1] = dp[i]

        if i > 0:
            while len(maxq) and maxq[0] < i - k:
                maxq.popleft()
            dp[i + 1] = max(dp[i + 1], dp[maxq[0]] - pre[maxq[0]] + pre[i])

        while len(maxq) and dp[i] - pre[i] >= dp[maxq[-1]] - pre[maxq[-1]]:
            maxq.pop()
        maxq.append(i)

    print(dp[n + 1])


solve()
