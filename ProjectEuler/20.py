fac = lambda x: 1 if x == 1 else x * fac(x - 1)
print(sum(map(lambda x: ord(x) - ord("0"), str(fac(100)))))
