class Solution {
public:
    string getPermutation(int n, int k) {
        int cnt = 0, vis = 0;
        std::string ans(n, '1');
        auto dfs = [&](this auto &&dfs, int curr) -> bool {
            if (curr == n) {
                if (++cnt == k) {
                    return true;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (~vis >> i & 1) {
                    vis ^= 1 << i;
                    ans[curr] = '0' + i;
                    if (dfs(curr + 1)) {
                        return true;
                    }
                    vis ^= 1 << i;
                }
            }
            return false;
        };
        dfs(0);
        return ans;
    }
};
