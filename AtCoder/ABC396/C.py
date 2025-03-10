import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    a.sort(reverse=True)
    b.sort(reverse=True)

    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + a[i]

    mx = n
    for i in range(n):
        if a[i] < 0:
            mx = i
            break

    ans = pre[mx]
    curr = 0
    for i in range(min(n, m)):
        curr += b[i]
        ans = max(ans, curr + pre[max(mx, i + 1)])

    print(ans)


solve()
