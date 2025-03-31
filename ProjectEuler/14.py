memo = {}


def dfs(n: int) -> int:
    if n == 1:
        return 1
    if n in memo:
        return memo[n]
    res = 1 + (dfs(n // 2) if n % 2 == 0 else dfs(3 * n + 1))
    memo[n] = res
    return res


ans, maxcnt = -1, -1
for i in range(1, 1000001):
    res = dfs(i)
    if res > maxcnt:
        maxcnt = res
        ans = i

print(ans)
