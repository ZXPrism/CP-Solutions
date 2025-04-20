class Solution {
public:
	vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
		std::vector<int> ans;
		int n = graph.size();
		std::vector<int> color(n);
		auto dfs = [&](this auto &&dfs, int node) -> bool {
			if (color[node]) {
				return color[node] == 1;
			}
			color[node] = 1;
			for (auto neighbor : graph[node]) {
				if (dfs(neighbor)) {
					return true;
				}
			}
			color[node] = 2;
			return false;
		};
		for (int i = 0; i < n; i++) {
			dfs(i);
		}
		for (int i = 0; i < n; i++) {
			if (color[i] == 2) {
				ans.push_back(i);
			}
		}
		return ans;
	}
};
