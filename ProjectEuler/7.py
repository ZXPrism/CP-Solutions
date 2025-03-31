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

print(primes[10000])
