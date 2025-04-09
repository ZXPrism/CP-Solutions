import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    v = list(map(int, input().split()))
    pre = [0] * (n + 1)
    ans = 0
    prev = 0
    for i in range(n):
        pre[i + 1] = (pre[i] + v[i]) % m
        ans += (i + 1) * pre[i + 1] - prev
        prev += pre[i + 1]
    fenwick = [0] * (m + 1)
    for i in range(n, -1, -1):
        curr = 0
        j = pre[i]
        while j:
            curr += fenwick[j]
            j -= j & -j
        ans += curr * m
        j = pre[i] + 1
        while j <= m:
            fenwick[j] += 1
            j += j & -j

    print(ans)


solve()
