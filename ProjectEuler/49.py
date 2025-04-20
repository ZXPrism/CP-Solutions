N = 10000
spf = [i for i in range(N + 1)]
spf[0] = spf[1] = -1
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

ans = []
vis = [0] * N
for i in range(1000, 10000):
    if not vis[i] and spf[i] == i:
        num = list(str(i))
        cand = set()
        for j in range(24):
            curr = int("".join(num))
            if curr >= 1000 and spf[curr] == curr:
                cand.add(curr)

            right = 2
            while right >= 0 and num[right] >= num[right + 1]:
                right -= 1

            if right >= 0:
                target = 3
                while num[target] <= num[right]:
                    target -= 1
                num[target], num[right] = num[right], num[target]
            num[right + 1 : 4] = num[right + 1 : 4][::-1]

        for elem in cand:
            vis[elem] = 1

        if len(cand) >= 3:
            v = list(cand)
            v.sort()
            n = len(v)
            for j in range(1, n - 1):
                target = 2 * v[j]
                left = 0
                right = n - 1
                while left < j and right > j:
                    s = v[left] + v[right]
                    if s == target:
                        ans.append((v[left], v[j], v[right]))
                        l = left
                        while left < j and v[left] == v[l]:
                            left += 1
                        r = right
                        while right > j and v[right] == v[r]:
                            right -= 1
                    elif s > target:
                        right -= 1
                    else:
                        left += 1
print(ans)
