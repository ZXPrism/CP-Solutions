class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size(), max_delta = std::max(x - arr.front(), arr.back() - x);

        int left = -1, right = max_delta + 1, mid = 0;
        auto check = [&](int delta) -> bool {
            int l = std::ranges::lower_bound(arr, x - delta) - arr.begin();
            int r = std::ranges::upper_bound(arr, x + delta) - arr.begin();
            return r - l >= k;
        };

        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }

        int a = std::ranges::upper_bound(arr, x + right) - arr.begin();
        int b = std::ranges::upper_bound(arr, x - right) - arr.begin();
        int c = std::ranges::lower_bound(arr, x + right) - arr.begin();
        int d = std::ranges::lower_bound(arr, x - right) - arr.begin();

        std::vector<int> ans(k);
        if (k <= c - d) {
            for (int i = 0; i < k; i++) {
                ans[i] = arr[i + c - k];
            }
        } else {
            for (int i = 0; i < k; i++) {
                ans[i] = arr[i + d];
            }
        }

        return ans;
    }
};
