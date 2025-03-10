import sys, heapq
from bisect import *
from collections import deque

input = sys.stdin.readline


def solve():
    n, m = map(int, input().split())
    adj = [[] for _ in range(n)]
    for i in range(m):
        u, v, w = map(int, input().split())
        u -= 1
        v -= 1
        adj[u].append((v, w))
        adj[v].append((u, w))

    vis = [False] * n
    ans = 1 << 61

    def dfs(node: int, curr: int):
        nonlocal ans

        if node == n - 1:
            ans = min(ans, curr)
            return

        for neighbor, weight in adj[node]:
            if not vis[neighbor]:
                vis[neighbor] = True
                dfs(neighbor, curr ^ weight)
                vis[neighbor] = False

    vis[0] = True
    dfs(0, 0)

    print(ans)


solve()
