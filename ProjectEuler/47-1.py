N = 1000000
spf = [i for i in range(N + 1)]
pcnt = [1] * (N + 1)
primes = []


for i in range(2, N + 1):
    if spf[i] == i:
        primes.append(i)
    for p in primes:
        if i * p > N:
            break
        spf[i * p] = p
        pcnt[i * p] = pcnt[i]
        if i % p == 0:
            break
        pcnt[i * p] += 1


i = 2
while i <= N:
    if not (pcnt[i] == 4):
        i += 1
        continue
    j = i + 1
    while j <= N and pcnt[j] == 4:
        j += 1
    if j - i >= 4:
        print(i)
        break
    i = j
