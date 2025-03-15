import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n, k, l = map(int, input().split())
    v = list(map(int, input().split()))
    v.sort(reverse=True)

    def check(h: int) -> bool:
        tot = 0
        for i in range(h):
            if h - v[i] > k:
                return False
            tot += max(0, h - v[i])
        return tot <= k * l

    left, right, mid = 0, n + 1, 0
    while left + 1 < right:
        mid = (left + right) >> 1
        if check(mid):
            left = mid
        else:
            right = mid

    print(left)


solve()
