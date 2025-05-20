class Solution {
public:
	int numEquivDominoPairs(vector<vector<int>> &dominoes) {
		int ans = 0;
		std::vector<std::vector<int>> cnt(10, std::vector<int>(10));
		for (auto &elem : dominoes) {
			auto [a, b] = std::minmax(elem[0], elem[1]);
			ans += cnt[a][b]++;
		}
		return ans;
	}
};
