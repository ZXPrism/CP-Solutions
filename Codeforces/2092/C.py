import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def solve():
    n = int(input())
    v = list(map(int, input().split()))
    # 1. all even -> no ops can be performed -> max(v)
    # 2. odd & even
    # 2.1 an odd number can always absorb an even and keeps its parity
    # 2.2 after any number of ops, the number of odds remain unchanged
    # so, the upper bound is sum(v) - odd + 1, can we achieve that?
    # 2.3 if we have multiple odds and at least one even
    # we can reduce all odds to 1 while keeps all parity
    # then select one odd to gather all evens
    # thus, the upper bound is achieved
    # 3. all odd -> no ops can be performed -> max(v)
    odd = 0
    for elem in v:
        odd += elem & 1
    if odd != 0 and odd != n:
        print(sum(v) - odd + 1)
    else:
        print(max(v))


t = int(input())
for _ in range(t):
    solve()
