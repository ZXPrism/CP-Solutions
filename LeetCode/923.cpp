class Solution {
public:
    int threeSumMulti(vector<int> &arr, int target) {
        std::ranges::sort(arr);
        int ans = 0;
        constexpr int MOD = 1'000'000'007;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if (sum == target) {
                    int a = left;
                    while (left <= right && arr[a] == arr[left]) {
                        ++left;
                    }
                    int b = right;
                    while (left <= right && arr[b] == arr[right]) {
                        --right;
                    }
                    if (left <= right || right != b) {
                        ans = (ans + (left - a) * (b - right)) % MOD;
                    } else {
                        ans = (ans + (b - a + 1) * (b - a) / 2) % MOD;
                    }
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        return ans;
    }
};
