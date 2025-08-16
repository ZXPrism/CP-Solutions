import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    ans = 0.0
    s = input()
    n = len(s)

    for i in range(n):
        if s[i] != "t":
            continue

        cnt = 0
        for j in range(i, n):
            if s[j] == "t":
                cnt += 1
                if j - i + 1 >= 3:
                    ans = max(ans, (cnt - 2) / (j - i - 1))

    print(ans)


t = 1
for _ in range(t):
    solve()
