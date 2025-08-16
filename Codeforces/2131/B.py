import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n = int(input())
    nn = n - (1 if n % 2 == 0 else 0)
    ans = []
    for i in range(nn):
        ans.append(-1 if i % 2 == 0 else 3)
    if n != nn:
        ans.append(2)
    print(" ".join(map(str, ans)))


t = int(input())
for _ in range(t):
    solve()
