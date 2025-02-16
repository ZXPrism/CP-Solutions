class Solution {
public:
    vector<int> decrypt(vector<int> &code, int k) {
        int n = code.size();

        std::vector<int> pre(2 * n + 1);
        for (int i = 0; i < 2 * n; i++) {
            pre[i + 1] = pre[i] + code[i % n];
        }

        std::vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (k >= 0) {
                ans[i] = pre[i + k + 1] - pre[i + 1];
            } else {
                ans[i] = pre[i + n] - pre[i + k + n];
            }
        }

        return ans;
    }
};
