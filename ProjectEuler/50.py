N = 1_000_000

spf = [i for i in range(N + 1)]
primes = []
for i in range(2, N + 1):
    if spf[i] == i:
        primes.append(i)
    for p in primes:
        if i * p > N:
            break
        spf[i * p] = p
        if i % p == 0:
            break

n_primes = len(primes)
pre = [0] * (n_primes + 1)
for i in range(n_primes):
    pre[i + 1] = pre[i] + primes[i]

max_prime = primes[-1]

max_cnt = 0
curr_res = 0

left = 0
for right in range(n_primes):
    while pre[right + 1] - pre[left] > max_prime:
        left += 1
    for i in range(left, right):
        num = pre[right + 1] - pre[i]
        if spf[num] == num and right - left + 1 > max_cnt:
            max_cnt = right - left + 1
            curr_res = num
            break

print(curr_res)
