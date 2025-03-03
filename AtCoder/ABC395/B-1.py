import sys
from bisect import *

input = sys.stdin.readline


def solve():
    n = int(input())
    grid = [["."] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if min(i, j, n - 1 - i, n - 1 - j) % 2 == 0:
                grid[i][j] = "#"
    for i in range(n):
        print("".join(grid[i]))


solve()
