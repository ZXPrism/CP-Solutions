N = 1001
x, y = N // 2, N // 2
dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
d = 0

step_limit = 1
step = 0
step_repeat = 0

ans = 0
for i in range(N**2):
    if x == y or x + y == N - 1:
        ans += i + 1

    x += dx[d]
    y += dy[d]

    step += 1
    if step == step_limit:
        step = 0
        step_repeat += 1
        if step_repeat == 2:
            step_repeat = 0
            step_limit += 1

        d = (d + 1) % 4

print(ans)
