class Solution {
public:
    vector<int> getStrongest(vector<int> &arr, int k) {
        int n = arr.size();
        std::ranges::sort(arr);
        int mid_val = arr[(n - 1) / 2];
        std::vector<int> ans(k);
        int left = 0, right = n - 1;
        for (int i = 0; i < k; i++) {
            int l = std::abs(arr[left] - mid_val);
            int r = std::abs(arr[right] - mid_val);
            if (l > r) {
                ans[i] = arr[left];
                ++left;
            } else if (l < r) {
                ans[i] = arr[right];
                --right;
            } else if (arr[left] > arr[right]) {
                ans[i] = arr[left];
                ++left;
            } else {
                ans[i] = arr[right];
                --right;
            }
        }
        return ans;
    }
};
