def gcd(a: int, b: int) -> int:
    return a if b == 0 else gcd(b, a % b)


def lcm(a: int, b: int) -> int:
    return a * b // gcd(a, b)


ans = 1
for i in range(2, 21):
    ans = lcm(ans, i)

print(ans)
