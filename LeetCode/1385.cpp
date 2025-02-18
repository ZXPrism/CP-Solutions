class Solution {
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d) {
        int ans = 0;
        std::ranges::sort(arr1);
        std::ranges::sort(arr2);
        for (auto elem : arr1) {
            auto l = std::ranges::lower_bound(arr2, elem - d) - arr2.begin();
            auto r = std::ranges::upper_bound(arr2, elem + d) - arr2.begin();
            if (l == r) {
                ++ans;
            }
        }
        return ans;
    }
};
