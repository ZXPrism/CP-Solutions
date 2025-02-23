class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        int left = -1, right = x, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (1LL * mid * mid <= x) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};
