a = 1
b = 2
c = 0
ans = 2
while c <= 4000000:
    if c % 2 == 0:
        ans += c
    c = a + b
    a = b
    b = c
print(ans)
