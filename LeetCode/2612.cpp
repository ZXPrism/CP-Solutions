class Solution {
public:
    class DSU {
    public:
        explicit DSU(size_t n) {
            _Parent = std::vector<int>(n + 1, -1);
        }

        int Find(int x) {
            return (_Parent[x] < 0 ? x : _Parent[x] = Find(_Parent[x]));
        }

        void Unite(int x, int y) {
            _Parent[Find(x)] = Find(y);
        }

        bool Same(int x, int y) {
            return Find(x) == Find(y);
        }

        int GetSize(int x) {
            return -_Parent[Find(x)];
        }

    private:
        std::vector<int> _Parent;
    };

    vector<int> minReverseOperations(int n, int p, vector<int> &banned, int k) {
        DSU dsu(n + 2);
        dsu.Unite(p, p + 2);
        for (auto x : banned) {
            dsu.Unite(x, x + 2);
        }

        std::queue<int> q;
        std::vector<int> dist(n, -1);

        dist[p] = 0;
        q.push(p);
        while (!q.empty()) {
            auto u = q.front();
            q.pop();

            int left = std::max(u - k + 1, k - 1 - u);
            int right = std::min(u + k - 1, 2 * n - k - 1 - u);
            for (int v = dsu.Find(left); v <= right; v = dsu.Find(v + 2)) {
                dist[v] = dist[u] + 1;
                q.push(v);
                dsu.Unite(v, right + 2);
            }
        }

        return dist;
    }
};
