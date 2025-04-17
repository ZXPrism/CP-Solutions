def binpow(a: int, b: int, m: int) -> int:
    res = 1
    while b:
        if b & 1:
            res = (res * a) % m
        a = (a * a) % m
        b >>= 1
    return res


print(sum([binpow(i, i, 10000000000) for i in range(1, 1001)]) % 10000000000)
