import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    v = list(map(int, input().split()))
    seg = []
    for i in range(1, n):
        seg.append(v[i] - v[i - 1])
    seg.sort(reverse=True)
    print(v[n - 1] - v[0] - sum(seg[: m - 1]) + m)


solve()
