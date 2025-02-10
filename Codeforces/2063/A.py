import sys

input = sys.stdin.readline


def solve():
    a, b = map(int, input().split())
    if a < b:
        print(b - a)
    else:
        print(1 if a == 1 else 0)


t = int(input())
for _ in range(t):
    solve()
