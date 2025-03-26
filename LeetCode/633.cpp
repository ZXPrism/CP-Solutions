class Solution {
public:
    bool judgeSquareSum(int c) {
        int left = 0, right = static_cast<int>(std::sqrt(1LL << 31));
        while (left <= right) {
            long long sum = 1LL * left * left + right * right;
            if (sum > c) {
                --right;
            } else if (sum < c) {
                ++left;
            } else {
                return true;
            }
        }
        return false;
    }
};
