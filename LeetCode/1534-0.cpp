class Solution {
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
        int n = arr.size(), ans = 0;
        std::vector<int> cnt(1002);
        auto qry = [&](int x) -> int {
            int res = 0;
            while (x) {
                res += cnt[x];
                x -= x & -x;
            }
            return res;
        };
        auto add = [&](int x) {
            while (x <= 1001) {
                ++cnt[x];
                x += x & -x;
            }
        };
        for (int j = 0; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (std::abs(arr[j] - arr[k]) <= b) {
                    int lb = std::max(0, std::max(arr[j] - a, arr[k] - c));
                    int ub = std::min(1000, std::min(arr[j] + a, arr[k] + c));
                    if (lb <= ub) {
                        ans += qry(ub + 1) - qry(lb);
                    }
                }
            }
            add(arr[j] + 1);
        }
        return ans;
    }
};
