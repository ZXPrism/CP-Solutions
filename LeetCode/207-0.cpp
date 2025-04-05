class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        std::vector<std::vector<int>> adj(numCourses);
        std::vector<int> in_deg(numCourses);
        for (auto &edge : prerequisites) {
            adj[edge[1]].push_back(edge[0]);
            ++in_deg[edge[0]];
        }
        std::queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (!in_deg[i]) {
                q.push(i);
            }
        }
        int cnt = 0;
        while (!q.empty()) {
            int start = q.front();
            q.pop();
            ++cnt;
            for (auto neighbor : adj[start]) {
                if (--in_deg[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        return cnt == numCourses;
    }
};
