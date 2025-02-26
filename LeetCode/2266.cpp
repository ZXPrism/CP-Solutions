class Solution {
public:
    int countTexts(string pressedKeys) {
        constexpr int MOD = 1'000'000'007;
        int n = pressedKeys.size();

        std::vector<int> dp3(n + 1);
        dp3[0] = 1;
        std::vector<int> dp4(n + 1);
        dp4[0] = 1;

        std::vector<int> use3(10);
        use3[2] = use3[3] = use3[4] = use3[5] = use3[6] = use3[8] = 1;

        for (int i = 0; i <= n; i++) {
            for (int j = 1; j <= 4; j++) {
                if (i < j) {
                    break;
                }
                if (j <= 3) {
                    dp3[i] = (dp3[i] + dp3[i - j]) % MOD;
                }
                dp4[i] = (dp4[i] + dp4[i - j]) % MOD;
            }
        }

        int ans = 1;
        for (int left = 0; left < n;) {
            int right = left + 1;
            while (right < n && pressedKeys[left] == pressedKeys[right]) {
                ++right;
            }
            if (use3[pressedKeys[left] - '0']) {
                ans = (1LL * ans * dp3[right - left]) % MOD;
            } else {
                ans = (1LL * ans * dp4[right - left]) % MOD;
            }
            left = right;
        }

        return ans;
    }
};
