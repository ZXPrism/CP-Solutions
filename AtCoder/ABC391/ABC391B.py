import sys

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())

    S = [""] * n
    T = [""] * m
    for i in range(n):
        S[i] = input().strip()
    for i in range(m):
        T[i] = input().strip()

    for i in range(n - m + 1):
        for j in range(n - m + 1):
            flag = True
            for x in range(m):
                for y in range(m):
                    if S[i + x][j + y] != T[x][y]:
                        flag = False
                        break
                if flag == False:
                    break
            if flag:
                print(i + 1, j + 1)
                return


t = 1
for _ in range(t):
    solve()
