class Solution {
public:
	int countCoveredBuildings(int n, vector<vector<int>> &buildings) {
		std::unordered_map<int, std::vector<int>> row;
		std::unordered_map<int, std::vector<int>> col;
		for (auto &b : buildings) {
			row[b[0]].push_back(b[1]);
			col[b[1]].push_back(b[0]);
		}
		for (auto &[_, r] : row) {
			std::ranges::sort(r);
		}
		for (auto &[_, c] : col) {
			std::ranges::sort(c);
		}
		int ans = 0;
		for (auto &b : buildings) {
			auto &r = row[b[0]], &c = col[b[1]];
			int r1 = std::ranges::lower_bound(r, b[1]) - r.begin();
			int r2 = std::ranges::upper_bound(r, b[1]) - r.begin();
			int c1 = std::ranges::lower_bound(c, b[0]) - c.begin();
			int c2 = std::ranges::upper_bound(c, b[0]) - c.begin();
			if (r1 != 0 && r2 != r.size() && c1 != 0 && c2 != c.size()) {
				++ans;
			}
		}
		return ans;
	}
};
