import sys, heapq
from bisect import bisect_left, bisect_right
from collections import deque

input = sys.stdin.readline().strip


def solve():
    s = input().strip()
    n = len(s)

    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + (1 if s[i] == "I" else 0)

    ans = n
    term_min = n
    for seg3_start in range(2, n):
        seg3_cost = (n - seg3_start) - (pre[n] - pre[seg3_start])
        term_min = min(term_min, seg3_start - 1 - 2 * pre[seg3_start - 1])
        ans = min(ans, pre[seg3_start] + term_min + seg3_cost)

    print(ans)


# t = int(input())
t = 1
for _ in range(t):
    solve()
