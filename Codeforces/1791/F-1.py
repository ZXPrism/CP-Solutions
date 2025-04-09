import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def solve():
    n, q = map(int, input().split())
    v = list(map(int, input().split()))

    fa = [-1] * (n + 1)

    def Find(x: int) -> int:
        y = x
        while fa[y] >= 0:
            y = fa[y]
        while fa[x] >= 0:
            fa[x], x = y, fa[x]
        return y

    for _ in range(q):
        question = list(map(int, input().split()))
        if question[0] == 1:
            i = Find(question[1] - 1)
            while i < question[2]:
                s = 0
                while v[i]:
                    s += v[i] % 10
                    v[i] //= 10
                v[i] = s
                if s < 10:
                    fa[i] = i + 1
                i = Find(i + 1)
        else:
            print(v[question[1] - 1])


t = int(input())
for _ in range(t):
    solve()
