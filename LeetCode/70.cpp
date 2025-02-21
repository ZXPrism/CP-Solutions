// #1. dp[i] = dp[i-1] + dp[i-2], i >= 1
// dp[0] = 1, dp[-1] = 0

// or

// #2. dp[0] = 1, dp[1] = 1
// dp[i] = dp[i-1] + dp[i-2], i >= 2

class Solution {
public:
    int climbStairs(int n) {
        std::vector<int> dp(n + 1);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

// space optimization for #1:
// a = 0, b = 1, c = ?
// c = a + b
// a = b, b = c

// space opti. for #2:
// a = 1, b = 1, c = ?
// c = a + b
// a = b, b = c
// failed -> assumed n >= 2 !

// NOTE: 从最小可计算的状态（此处为 n = 1）开始计算
