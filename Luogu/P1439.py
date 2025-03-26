import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    v = [0] * (n + 1)
    for i, elem in enumerate(b):
        v[elem] = i
    f = []
    for elem in a:
        x = bisect_left(f, v[elem])
        if x == len(f):
            f.append(v[elem])
        else:
            f[x] = v[elem]
    print(len(f))


t = 1
# t = int(input())
for _ in range(t):
    solve()
