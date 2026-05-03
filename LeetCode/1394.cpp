class Solution {
public:
	int findLucky(vector<int> &arr) {
		int ans = -1;
		std::vector<int> cnt(501);
		for (auto elem : arr) {
			++cnt[elem];
		}
		for (auto elem : arr) {
			if (elem == cnt[elem]) {
				ans = std::max(ans, elem);
			}
		}
		return ans;
	}
};
