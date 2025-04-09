import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def solve():
    n, q = map(int, input().split())
    v = list(map(int, input().split()))
    fenwick = [0] * (n + 2)

    def update(left: int, right: int):
        def add(i: int, val: int):
            while i <= n:
                fenwick[i] += val
                i += i & -i

        add(right + 1, -1)
        add(left, 1)

    def query(i: int):
        res = 0
        while i:
            res += fenwick[i]
            i -= i & -i
        return res

    for _ in range(q):
        question = list(map(int, input().split()))
        if question[0] == 1:
            update(question[1], question[2])
        else:
            cnt = query(question[1])
            val = v[question[1] - 1]
            if val > 9:
                for i in range(min(3, cnt)):
                    new_val = 0
                    while val:
                        new_val += val % 10
                        val //= 10
                    val = new_val
            print(val)


t = int(input())
for _ in range(t):
    solve()
