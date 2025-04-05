class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        for (auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
        }
        std::vector<int> color(numCourses);
        auto dfs = [&](this auto &&dfs, int node) -> bool {
            color[node] = 1;
            for (auto neighbor : adj[node]) {
                if (color[neighbor] == 1 || color[neighbor] == 0 && dfs(neighbor)) {
                    return true;
                }
            }
            color[node] = 2;
            return false;
        };
        for (int i = 0; i < numCourses; i++) {
            if (color[i] == 0) {
                if (dfs(i)) {
                    return false;
                }
            }
        }
        return true;
    }
};
