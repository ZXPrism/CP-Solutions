class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size();
        int partition = std::ranges::lower_bound(arr, x) - arr.begin();
        int left = partition - 1, right = partition;
        while (k--) {
            if (left < 0) {
                ++right;
            } else if (right == n) {
                --left;
            } else if (x - arr[left] <= arr[right] - x) {
                --left;
            } else {
                ++right;
            }
        }
        return std::vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};
