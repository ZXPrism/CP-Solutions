import sys
from bisect import *

input = sys.stdin.readline


def solve():
    n = int(input())
    v = list(map(int, input().split()))

    s = sum(v)
    even = sum([v[i] for i in range(n) if i % 2 == 0])
    odd = s - even
    even_cnt = (n + 1) // 2
    odd_cnt = n - even_cnt

    if even % even_cnt != 0 or odd % odd_cnt != 0 or even // even_cnt != odd // odd_cnt:
        print("NO")
        return

    print("YES")


t = int(input())
for _ in range(t):
    solve()
