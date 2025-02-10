import sys

input = sys.stdin.readline


def solve():
    d = list(input().strip())
    n = len(d)
    for i in range(n):
        if d[i] == "N":
            d[i] = "S"
        elif d[i] == "S":
            d[i] = "N"
        elif d[i] == "W":
            d[i] = "E"
        else:
            d[i] = "W"
    print("".join(d))


t = 1
for _ in range(t):
    solve()
