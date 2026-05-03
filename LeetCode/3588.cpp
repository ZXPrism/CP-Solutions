class Solution {
public:
	long long maxArea(vector<vector<int>> &coords) {
		long long ans = 0;
		int min_x = 1e9, max_x = -1e9;
		int min_y = 1e9, max_y = -1e9;
		std::unordered_map<int, std::pair<int, int>> hx, hy;
		for (const auto &pos : coords) {
			min_x = std::min(min_x, pos[0]);
			min_y = std::min(min_y, pos[1]);
			max_x = std::max(max_x, pos[0]);
			max_y = std::max(max_y, pos[1]);
			if (!hx.contains(pos[0])) {
				hx[pos[0]] = { pos[1], pos[1] };
			} else {
				hx[pos[0]].first = std::min(hx[pos[0]].first, pos[1]);
				hx[pos[0]].second = std::max(hx[pos[0]].second, pos[1]);
			}
			if (!hy.contains(pos[1])) {
				hy[pos[1]] = { pos[0], pos[0] };
			} else {
				hy[pos[1]].first = std::min(hy[pos[1]].first, pos[0]);
				hy[pos[1]].second = std::max(hy[pos[1]].second, pos[0]);
			}
		}
		for (auto &[x, pos_range] : hx) {
			ans = std::max(ans, 1LL * (pos_range.second - pos_range.first) *
			                        std::max(x - min_x, max_x - x));
		}
		for (auto &[y, pos_range] : hy) {
			ans = std::max(ans, 1LL * (pos_range.second - pos_range.first) *
			                        std::max(y - min_y, max_y - y));
		}
		return (!ans ? -1 : ans);
	}
};
