import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def OK(x: int) -> bool:
    if x == 1:
        return False
    sqr = int(x**0.5)
    for i in range(2, sqr + 1):
        if x % i == 0:
            return False
    return True


def solve():
    x, k = map(int, input().split())
    if x == 1:
        print("YES" if OK(int("1" * k)) else "NO")
        return
    if k >= 2:
        print("NO")
        return
    print("YES" if OK(x) else "NO")


t = int(input())
for _ in range(t):
    solve()
