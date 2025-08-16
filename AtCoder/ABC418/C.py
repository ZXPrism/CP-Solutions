import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n, q = map(int, input().split())

    v = list(map(int, input().split()))
    v.sort()

    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + v[i]

    mx = max(v)

    for _ in range(q):
        b = int(input())
        if b > mx:
            print(-1)
        else:
            x = bisect_left(v, b - 1)
            print(pre[x] + (b - 1) * (n - x) + 1)


t = 1
for _ in range(t):
    solve()
