class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size(), ans = k, sum = 0;
        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'W') {
                ++sum;
            }
            if (i >= k - 1) {
                ans = std::min(ans, sum);
                if (blocks[i - k + 1] == 'W') {
                    --sum;
                }
            }
        }
        return ans;
    }
};
