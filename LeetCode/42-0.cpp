class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        std::vector<int> pre_max(n + 1), suf_max(n + 2);
        for (int i = 0; i < n; i++) {
            pre_max[i + 1] = std::max(pre_max[i], height[i]);
        }
        for (int i = n - 1; i >= 0; i--) {
            suf_max[i + 1] = std::max(suf_max[i + 2], height[i]);
        }
        int ans = 0;
        for (int i = 1; i < n - 1; i++) {
            ans += std::max(0, std::min(pre_max[i], suf_max[i + 2]) - height[i]);
        }
        return ans;
    }
};
