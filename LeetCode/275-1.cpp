class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int left = 0, right = n + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (citations[n - mid] >= mid) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
