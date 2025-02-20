class Solution {
public:
    vector<int> evenOddBit(int n) {
        int even = 0, odd = 0, flag = 0;
        while (n) {
            if (!flag) {
                even += n & 1;
            } else {
                odd += n & 1;
            }
            n >>= 1;
            flag ^= 1;
        }
        return {even, odd};
    }
};
