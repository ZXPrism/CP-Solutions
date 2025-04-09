import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def solve():
    s = input().strip()
    cnt = [0] * 26
    for ch in s:
        cnt[ord(ch) - ord("a")] += 1
    n = len(s)
    if n > 26 * 99:
        for i in range(26):
            if cnt[i] >= 100:
                print(chr(i + ord("a")) * 100)
                return

    dp = [[0] * n for _ in range(n)]
    for i in range(n):
        dp[i][i] = 1
        for j in range(i - 1, -1, -1):
            if s[i] == s[j]:
                dp[i][j] = dp[i - 1][j + 1] + 2
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j + 1])

    i, j = 0, n - 1
    ans = []
    while i < j and len(ans) != 50:
        if s[i] == s[j]:
            ans.append(s[i])
            i += 1
            j -= 1
        elif dp[j][i + 1] == dp[j][i]:
            i += 1
        else:
            j -= 1

    rev = ans[::-1]
    if i == j and len(ans) != 50:
        ans.append(s[i])

    print("".join(ans + rev))


solve()
