class Solution {
public:
    long long maximumOr(vector<int> &nums, int k) {
        int n = nums.size();
        long long ans = 0;

        int max_elem = 0;
        std::vector<int> bits(31);
        for (auto elem : nums) {
            for (int i = 0; i < 31; i++) {
                bits[i] += elem >> i & 1;
            }
            max_elem = std::max(max_elem, elem);
        }

        int eigen = __builtin_clz(max_elem);
        for (auto elem : nums) {
            if (__builtin_clz(elem) == eigen) {
                int residue = 0;
                for (int i = 0; i < 31; i++) {
                    if (bits[i] - (elem >> i & 1)) {
                        residue |= 1 << i;
                    }
                }
                ans = std::max(ans, residue | (1LL * elem << k));
            }
        }

        return ans;
    }
};
