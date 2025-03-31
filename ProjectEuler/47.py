N = 1000000
minp = [i for i in range(N + 1)]
primes = []
for i in range(2, N + 1):
    if minp[i] == i:
        primes.append(i)
    for p in primes:
        if i * p > N:
            break
        minp[i * p] = p
        if i % p == 0:
            break


def ok(x: int) -> bool:
    pfac = set()
    while x != 1:
        pfac.add(minp[x])
        x //= minp[x]
    return len(pfac) == 4


i = 2
while i <= N:
    if not ok(i):
        i += 1
        continue
    j = i + 1
    while j <= N and ok(j):
        j += 1
    if j - i >= 4:
        print(i)
        break
    i = j
