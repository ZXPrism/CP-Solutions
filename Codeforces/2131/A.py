import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n = int(input())
    v1 = list(map(int, input().split()))
    v2 = list(map(int, input().split()))
    ans = 1
    for i in range(n):
        ans += max(0, v1[i] - v2[i])
    print(ans)


t = int(input())
for _ in range(t):
    solve()
