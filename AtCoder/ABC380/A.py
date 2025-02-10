import sys

input = sys.stdin.readline


def solve():
    num = input().strip()
    cnt = [0] * 10
    for ch in num:
        cnt[ord(ch) - 48] += 1
    if cnt[1] == 1 and cnt[2] == 2 and cnt[3] == 3:
        print("Yes")
    else:
        print("No")


t = 1
for _ in range(t):
    solve()
