import sys

input = sys.stdin.readline


def solve():
    a, b = map(int, input().split())
    print(a + b)


t = 1
for _ in range(t):
    solve()
