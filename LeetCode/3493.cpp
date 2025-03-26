class Solution {
public:
    int numberOfComponents(vector<vector<int>> &properties, int k) {
        int n = properties.size();
        std::vector<std::bitset<101>> code(n);
        for (int i = 0; i < n; i++) {
            for (auto elem : properties[i]) {
                code[i].set(elem);
            }
        }
        int ans = n;
        std::vector<int> fa(n, -1);
        auto Find = [&](auto &&self, int node) -> int {
            return fa[node] < 0 ? node : fa[node] = self(self, fa[node]);
        };
        auto Merge = [&](int from, int to) -> void {
            from = Find(Find, from);
            to = Find(Find, to);
            if (from != to) {
                fa[from] = to;
                --ans;
            }
        };
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if ((code[i] & code[j]).count() >= k) {
                    Merge(i, j);
                }
            }
        }
        return ans;
    }
};
