# abundant number: 所有真因子之和大于自身
# 所有大于 28123 的数都可以写成两个 abundant number 之和
# -> 求所有小于等于 28123 的数中，不能写成两个 abundant number 之和的数的和

# 无论如何，首先需要生成所有 abundant number

N = 28123
divisor_sums = [0] * (N + 1)
for i in range(1, N + 1):
    for j in range(i, N + 1, i):
        divisor_sums[j] += i

abundant_nums = []
for i in range(1, N + 1):
    if divisor_sums[i] - i > i:
        abundant_nums.append(i)

print(len(abundant_nums))  # 6965 个

# 如果暴力枚举所有数，检查它们是否满足条件，利用双指针可以做到 O(k)，k = 6965
# 6965 * 28123 = 195876695，大概需要跑五秒

# 不如用所有 abundant num 去筛掉不满足条件的数
# 6965 ** 2 = 48511225，需要一秒左右

n_abundant_nums = len(abundant_nums)
vis = [True] * (N + 1)
for i in range(n_abundant_nums):
    for j in range(i, n_abundant_nums):
        s = abundant_nums[i] + abundant_nums[j]
        if s <= N:
            vis[s] = False

ans = 0
for i in range(1, N + 1):
    if vis[i]:
        ans += i
print(ans)
