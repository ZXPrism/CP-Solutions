class Solution {
public:
    int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
        int n = nums.size();
        std::vector<std::vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int timestamp = 0;
        std::vector<int> in(n), out(n);
        std::vector<int> xor_val(n);
        auto dfs = [&](auto &&self, int node, int fa) -> void {
            in[node] = ++timestamp;
            xor_val[node] = nums[node];
            for (auto neighbor : adj[node]) {
                if (neighbor != fa) {
                    self(self, neighbor, node);
                    xor_val[node] ^= xor_val[neighbor];
                }
            }
            out[node] = timestamp;
        };
        dfs(dfs, 0, -1);

        auto is_ancestor = [&](int des, int ans) -> bool {
            return in[ans] <= in[des] && out[des] <= out[ans];
        };

        for (auto &e : edges) {
            if (is_ancestor(e[1], e[0])) {
                std::swap(e[0], e[1]);
            }
        }

        int ans = std::numeric_limits<int>::max();
        int n_edges = edges.size();
        for (int i = 0; i < n_edges; i++) {
            int x1 = edges[i][0], y1 = edges[i][1];
            for (int j = i + 1; j < n_edges; j++) {
                int x2 = edges[j][0], y2 = edges[j][1];
                int a = 0, b = 0, c = 0;
                if (is_ancestor(y1, x2)) {
                    a = xor_val[0] ^ xor_val[x2];
                    b = xor_val[x2] ^ xor_val[x1];
                    c = xor_val[x1];
                } else if (is_ancestor(y2, x1)) {
                    a = xor_val[0] ^ xor_val[x1];
                    b = xor_val[x1] ^ xor_val[x2];
                    c = xor_val[x2];
                } else {
                    a = xor_val[0] ^ xor_val[x1] ^ xor_val[x2];
                    b = xor_val[x1];
                    c = xor_val[x2];
                }
                ans = std::min(ans, std::max({a, b, c}) - std::min({a, b, c}));
            }
        }

        return ans;
    }
};
