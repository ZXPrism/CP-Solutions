import sys, heapq
from bisect import *
from collections import deque, Counter

input = sys.stdin.readline


def solve():
    n = int(input())
    v = list(map(int, input().split()))

    special_idx = n
    for i in range(n):
        if v[i] != 1 and v[i] != -1:
            special_idx = i
            break

    segments = [(0, 0)]
    curr_max, curr_min = 0, 0
    for i in range(special_idx):
        curr_max = max(curr_max, 0) + v[i]
        curr_min = min(curr_min, 0) + v[i]
        segments.append((curr_min, curr_max))
        if special_idx != n and i == special_idx - 1:
            segments.append((curr_min + v[special_idx], curr_max + v[special_idx]))

    if special_idx != n:
        segments.append((v[special_idx], v[special_idx]))

        curr_max, curr_min = 0, 0
        for i in range(n - 1, special_idx, -1):
            curr_max = max(curr_max, 0) + v[i]
            curr_min = min(curr_min, 0) + v[i]
            segments.append((curr_min, curr_max))
            if i == special_idx + 1:
                segments.append((curr_min + v[special_idx], curr_max + v[special_idx]))

        pre = 0
        minp, maxp = 0, 0
        for i in range(n):
            if i == special_idx:
                continue

            pre += v[i]
            if i > special_idx:
                segments.append(
                    (pre - maxp + v[special_idx], pre - minp + v[special_idx])
                )

            if i < special_idx:
                minp = min(minp, pre)
                maxp = max(maxp, pre)

    segments.sort(key=lambda x: x[0])

    merged = []
    n_segments = len(segments)
    tot = 0
    i = 0
    while i < n_segments:
        j = i + 1
        right = segments[i][1]
        while j < n_segments and segments[j][0] <= right:
            right = max(right, segments[j][1])
            j += 1
        tot += right - segments[i][0] + 1
        merged.append((segments[i][0], right))
        i = j

    print(tot)
    for seg in merged:
        for i in range(seg[0], seg[1] + 1):
            print(i, end=" ")
    print()


t = int(input())
for _ in range(t):
    solve()
