class Solution {
public:
    int maxArea(vector<int> &height) {
        int n = height.size(), ans = 0;
        std::vector<int> pos(n);
        std::iota(pos.begin(), pos.end(), 0);
        std::ranges::sort(pos, [&](int lhs, int rhs) { return height[lhs] > height[rhs]; });
        int min_idx = pos[0], max_idx = pos[0];
        for (int i = 1; i < n; i++) {
            ans = std::max(ans, height[pos[i]] * std::abs(pos[i] - min_idx));
            ans = std::max(ans, height[pos[i]] * std::abs(pos[i] - max_idx));
            min_idx = std::min(min_idx, pos[i]);
            max_idx = std::max(max_idx, pos[i]);
        }
        return ans;
    }
};
