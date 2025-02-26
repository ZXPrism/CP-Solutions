class Solution {
public:
    int maxLength(vector<int> &ribbons, int k) {
        int n = ribbons.size();
        auto check = [&](int len) -> bool {
            long long tot = 0;
            for (int i = 0; i < n; i++) {
                tot += ribbons[i] / len;
            }
            return tot >= k;
        };
        int left = 0, right = 100001, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
