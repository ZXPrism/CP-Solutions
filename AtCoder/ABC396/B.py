import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    s = []
    q = int(input())
    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            s.append(query[1])
        else:
            if len(s) == 0:
                print(0)
            else:
                print(s[-1])
                s.pop()


solve()
