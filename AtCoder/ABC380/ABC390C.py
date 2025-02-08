import sys

input = sys.stdin.readline


def solve():
    n, k = map(int, input().split())
    s = input().strip()

    start, end = -1, -1
    left = 0
    oneID = 0
    while left < n:
        right = left + 1
        while right < n and s[right] == s[left]:
            right += 1

        if s[left] == "1":
            oneID += 1
            if oneID == k:
                start, end = left, right - 1
                break

        left = right

    blockLen = end - start + 1
    newStart = start - 1
    while newStart >= 0 and s[newStart] == "0":
        newStart -= 1
    newStart += 1

    result = []
    result.append(s[:newStart])
    for i in range(blockLen):
        result.append("1")
    for i in range(start - newStart):
        result.append("0")
    result.append(s[end + 1 : n])

    print("".join(result))


t = 1
for _ in range(t):
    solve()
