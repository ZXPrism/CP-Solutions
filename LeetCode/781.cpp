class Solution {
public:
	int numRabbits(vector<int> &answers) {
		std::vector<int> cnt(1000);
		for (auto elem : answers) {
			++cnt[elem];
		}
		int ans = 0;
		for (int i = 0; i < 1000; i++) {
			ans += (cnt[i] + i) / (i + 1) * (i + 1);
		}
		return ans;
	}
};
