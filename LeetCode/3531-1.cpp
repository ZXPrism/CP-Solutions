class Solution {
public:
	int countCoveredBuildings(int n, vector<vector<int>> &buildings) {
		std::unordered_map<int, int> r1, r2;
		std::unordered_map<int, int> c1, c2;

		for (auto &b : buildings) {
			r1[b[0]] = n + 1;
			c1[b[1]] = n + 1;
		}

		for (auto &b : buildings) {
			r1[b[0]] = std::min(r1[b[0]], b[1]);
			r2[b[0]] = std::max(r2[b[0]], b[1]);
			c1[b[1]] = std::min(c1[b[1]], b[0]);
			c2[b[1]] = std::max(c2[b[1]], b[0]);
		}

		int ans = 0;
		for (auto &b : buildings) {
			auto cmin = r1[b[0]], cmax = r2[b[0]];
			auto rmin = c1[b[1]], rmax = c2[b[1]];
			if (b[1] != cmin && b[1] != cmax && b[0] != rmin && b[0] != rmax) {
				++ans;
			}
		}

		return ans;
	}
};
