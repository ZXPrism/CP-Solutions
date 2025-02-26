class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>> &points, string s) {
        int n = points.size();

        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);

        auto F = [](const std::vector<int> &v) -> int {
            return std::max(std::abs(v[0]), std::abs(v[1]));
        };

        std::ranges::sort(idx, [&](int lhs, int rhs) { return F(points[lhs]) < F(points[rhs]); });

        std::vector<int> marked(26);
        for (int left = 0; left < n;) {
            int right = left + 1;
            while (right < n && F(points[idx[left]]) == F(points[idx[right]])) {
                ++right;
            }
            for (int i = left; i < right; i++) {
                auto &state = marked[s[idx[i]] - 'a'];
                if (state) {
                    return left;
                } else {
                    state = 1;
                }
            }
            left = right;
        }

        return n;
    }
};
