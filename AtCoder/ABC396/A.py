import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n = int(input())
    v = list(map(int, input().split()))
    for i in range(n - 2):
        if v[i] == v[i + 1] and v[i + 1] == v[i + 2]:
            print("Yes")
            return
    print("No")


solve()
