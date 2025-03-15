// 1. use greedy to prove that we must select k consecutive numbers (a window with length k)
// 2. use binary search to minimize the max distance from x to any element in the window
// the max distance = max(abs(x - v[left]), abs(x - v[right])) = * max(x - v[left], v[right] - x) *
// => max(x - v[left], v[left + k - 1] - x)
// this function has a minimum value, but how to find that with binary search?

// problem: this function is not monotonic, there could be identical elements!
// so we have to make it unique before performing binary search? this would be inefficient!
// 25-02-22

// solved in 25-03-15! with a bit guess though.

class Solution {
public:
    vector<int> findClosestElements(vector<int> &arr, int k, int x) {
        int n = arr.size();
        int left = -1, right = n - k, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) >> 1;
            if (x - arr[mid] <= arr[mid + k] - x) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return std::vector<int>(arr.begin() + right, arr.begin() + right + k);
    }
};
