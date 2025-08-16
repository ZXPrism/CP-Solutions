import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    s = list(map(lambda x: int(x) % k, input().split()))
    t = list(map(lambda x: int(x) % k, input().split()))
    s = list(map(lambda x: min(x, k - x), s))
    t = list(map(lambda x: min(x, k - x), t))
    s.sort()
    t.sort()
    print("YES" if s == t else "NO")


t = int(input())
for _ in range(t):
    solve()
