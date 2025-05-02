k = 1000000  # 390304790967593360819076481 - riddle from https://projecteuler.net/thread=24;page=8

N = 10

fac = [1] * N
for i in range(1, N):
    fac[i] = fac[i - 1] * i

ans = []
used = [0] * N
for i in range(N - 1, -1, -1):
    for j in range(N):
        if used[j]:
            continue
        curr = fac[i]
        if k <= curr:
            used[j] = 1
            ans.append(str(j))
            break
        k -= curr

print("".join(ans))
