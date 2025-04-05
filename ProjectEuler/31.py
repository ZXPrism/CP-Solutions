coins = [1, 2, 5, 10, 20, 50, 100, 200]
dp = [0] * 201
dp[0] = 1
for i in range(len(coins)):
    for j in range(coins[i], 201):
        dp[j] += dp[j - coins[i]]
print(dp[200])
