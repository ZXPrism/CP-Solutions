import sys

input = sys.stdin.readline


def solve():
    s = input().strip()
    n = len(s)

    ans = []
    left, right = 0, 0
    while left < n:
        if s[left] == "|":
            left += 1
            continue
        right = left + 1
        while right < n and s[right] == "-":
            right += 1
        ans.append(str(right - left))
        left = right

    print(" ".join(ans))


t = 1
for _ in range(t):
    solve()
