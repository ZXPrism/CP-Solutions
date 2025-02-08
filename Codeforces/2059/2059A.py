import sys

input = sys.stdin.readline


def solve():
    n = int(input())
    a = set(map(int, input().split()))
    b = set(map(int, input().split()))
    print("YES" if len(a) * len(b) >= 3 else "NO")


t = int(input())
for _ in range(t):
    solve()
