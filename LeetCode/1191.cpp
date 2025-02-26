class Solution {
public:
    int kConcatenationMaxSum(vector<int> &arr, int k) {
        int n = arr.size();
        constexpr int MOD = 1'000'000'007;

        arr.resize(2 * n);
        for (int i = 0; i < n; i++) {
            arr[i + n] = arr[i];
        }

        int curr = 0;
        long long mx = 0, mx_ext = 0, sum = 0;
        for (int i = 0; i < 2 * n; i++) {
            curr = std::max(curr + arr[i], arr[i]);
            if (i < n) {
                mx = std::max(mx, 1LL * curr);
                sum += arr[i];
            }
            mx_ext = std::max(mx_ext, 1LL * curr);
        }

        long long ans = mx;
        if (k >= 2) {
            ans = std::max({ans, mx_ext, mx_ext + 1LL * (k - 2) * sum});
        }

        return ans % MOD;
    }
};
