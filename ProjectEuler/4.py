ans = 0

for i in range(100, 1000):
    for j in range(100, 1000):
        x = i * j
        sx = str(x)
        if sx == sx[::-1]:
            ans = max(ans, x)

print(ans)
