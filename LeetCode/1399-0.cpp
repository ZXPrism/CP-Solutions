class Solution {
public:
	int countLargestGroup(int n) {
		std::vector<int> sum(n + 1);
		std::vector<int> cnt(50);
		int max_cnt = 0;
		for (int i = 1; i <= n; i++) {
			sum[i] = sum[i / 10] + i % 10;
			++cnt[sum[i]];
			max_cnt = std::max(max_cnt, cnt[sum[i]]);
		}
		int ans = 0;
		for (int i = 0; i < 50; i++) {
			ans += (cnt[i] == max_cnt);
		}
		return ans;
	}
};
