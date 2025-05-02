class Solution {
public:
	int longestPath(vector<int> &parent, string s) {
		int n = parent.size();

		std::vector<std::vector<int>> from(n);
		for (int i = 1; i < n; i++) {
			from[parent[i]].push_back(i);
		}

		int ans = 0;
		auto dfs = [&](this auto &&dfs, int node) -> int {
			int max_len = 0, submax_len = 0;
			for (auto child : from[node]) {
				int res = dfs(child);
				if (s[child] != s[node]) {
					if (res > max_len) {
						submax_len = max_len;
						max_len = res;
					} else if (res > submax_len) {
						submax_len = res;
					}
				}
			}
			ans = std::max(ans, max_len + submax_len + 1);
			return max_len + 1;
		};
		dfs(0);

		return ans;
	}
};
