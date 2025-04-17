V = 100000
divisors = [[] for _ in range(V + 1)]
for i in range(1, V + 1):
    for j in range(i, V + 1, i):
        divisors[j].append(i)

s = list(map(lambda elem: sum(elem[1]) - elem[0], enumerate(divisors)))

ans = 0
for i in range(1, 10001):
    if i != s[i] and i == s[s[i]]:
        ans += i

print(ans)
