a = 1
b = 1
c = 0
cnt = 3

while True:
    c = a + b

    if len(str(c)) == 1000:
        print(cnt)
        break

    a = b
    b = c
    cnt += 1
