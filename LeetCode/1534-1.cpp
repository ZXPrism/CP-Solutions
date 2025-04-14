class Solution {
public:
    int countGoodTriplets(vector<int> &arr, int a, int b, int c) {
        int n = arr.size();
        std::vector<int> idx(n);
        std::ranges::iota(idx, 0);
        std::ranges::sort(idx, {}, [&](int i) { return arr[i]; });
        int ans = 0;
        for (auto j : idx) {
            std::vector<int> left, right;
            for (int i = 0; i < n; i++) {
                if (idx[i] < j && std::abs(arr[idx[i]] - arr[j]) <= a) {
                    left.push_back(arr[idx[i]]);
                }
                if (idx[i] > j && std::abs(arr[idx[i]] - arr[j]) <= b) {
                    right.push_back(arr[idx[i]]);
                }
            }
            int k1 = 0, k2 = 0;
            for (auto elem : right) {
                while (k1 < left.size() && left[k1] < elem - c) {
                    ++k1;
                }
                while (k2 < left.size() && left[k2] <= elem + c) {
                    ++k2;
                }
                ans += k2 - k1;
            }
        }
        return ans;
    }
};
