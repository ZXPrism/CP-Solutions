from collections import Counter

N = 1000000
primes = []
minp = [i for i in range(N + 1)]

for i in range(2, N + 1):
    if minp[i] == i:
        primes.append(i)
    for p in primes:
        if i * p > N:
            break
        minp[i * p] = p
        if i % p == 0:
            break


def Decomp(n: int) -> Counter:
    res = Counter()
    while n != 1:
        res[minp[n]] += 1
        n //= minp[n]
    return res


for i in range(1, 100001):
    a = Decomp(i)
    b = Decomp(i + 1)
    c = a + b
    c[2] -= 1

    fac_num = 1
    for _, cnt in c.items():
        fac_num *= cnt + 1

    if fac_num > 500:
        print(f"n = {i} val = {i*(i+1)//2} fac_num = {fac_num}")
        break
