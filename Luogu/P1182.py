import sys
from bisect import *

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    v = list(map(int, input().split()))

    pre = [0] * (n + 1)
    for i in range(n):
        pre[i + 1] = pre[i] + v[i]

    def check(limit: int) -> bool:
        cnt = 0
        left = 0
        while left < n:
            left = bisect_right(pre, pre[left] + limit) - 1
            cnt += 1
        return cnt <= m

    left, right, mid = max(v) - 1, int(1e8), 0
    while left + 1 < right:
        mid = (left + right) >> 1
        if check(mid):
            right = mid
        else:
            left = mid

    print(right)


solve()
