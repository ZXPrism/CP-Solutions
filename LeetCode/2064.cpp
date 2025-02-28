class Solution {
public:
    int minimizedMaximum(int n, vector<int> &quantities) {
        auto check = [&](int limit) -> bool {
            long long tot = 0;
            for (auto amount : quantities) {
                tot += (amount + limit - 1) / limit;
            }
            return tot <= n;
        };
        int left = 0, right = 1'000'01, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
