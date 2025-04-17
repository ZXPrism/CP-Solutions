k = 1000000

fac = [1] * 10
for i in range(1, 10):
    fac[i] = fac[i - 1] * i

ans = []
used = [0] * 10
for i in range(9, -1, -1):
    for j in range(10):
        if used[j]:
            continue
        curr = fac[i]
        if k <= curr:
            used[j] = 1
            ans.append(str(j))
            break
        k -= curr

print("".join(ans))
