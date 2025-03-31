C = [0] * (41 + 2)
C[1] = 1

for i in range(1, 41):
    for j in range(i, -1, -1):
        C[j + 1] += C[j]

print(C[21])
