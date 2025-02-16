class Solution {
public:
    int numOfSubarrays(vector<int> &arr, int k, int threshold) {
        int n = arr.size(), ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (i >= k - 1) {
                if (sum >= k * threshold) {
                    ++ans;
                }
                sum -= arr[i - k + 1];
            }
        }
        return ans;
    }
};
