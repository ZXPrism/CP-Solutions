n = 600851475143
sqrt_n = int(n**0.5)

ans = 0
for i in range(2, sqrt_n + 1):
    while n % i == 0:
        ans = i
        n /= i

if n != 1:
    ans = n

print(ans)
