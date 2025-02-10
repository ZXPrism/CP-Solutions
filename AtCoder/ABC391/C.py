import sys

input = sys.stdin.readline


def solve():
    n, q = map(int, input().split())
    pos = [i for i in range(n)]
    cnt = [1 for i in range(n)]
    target = 0

    for _ in range(q):
        query = list(map(int, input().split()))
        if query[0] == 1:
            query[1] -= 1
            query[2] -= 1
            cnt[pos[query[1]]] -= 1
            cnt[query[2]] += 1
            if cnt[pos[query[1]]] == 1:
                target -= 1
            if cnt[query[2]] == 2:
                target += 1
            pos[query[1]] = query[2]
        else:
            print(target)


t = 1
for _ in range(t):
    solve()
