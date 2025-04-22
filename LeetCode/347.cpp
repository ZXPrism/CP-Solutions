class Solution {
public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		constexpr int V = 10000;
		std::mt19937_64 engine;

		std::vector<int> cnt(2 * V + 1);
		for (auto elem : nums) {
			++cnt[elem + V];
		}
		std::vector<int> idx(2 * V + 1);
		std::ranges::iota(idx, 0);
		auto partition = [&](int left, int right) -> std::pair<int, int> {
			std::uniform_int_distribution<int> dist(left, right);
			int pivot = cnt[idx[dist(engine)]];
			int i = left, j = left, k = right + 1;
			while (i < k) {
				int curr = cnt[idx[i]];
				if (curr > pivot) {
					std::swap(idx[i], idx[j]);
					++j;
					++i;
				} else if (curr == pivot) {
					++i;
				} else {
					--k;
					std::swap(idx[i], idx[k]);
				}
			}
			return { j, k };
		};
		int left = 0, right = 2 * V, target = -1;
		while (1) {
			auto [L, R] = partition(left, right);
			if (k - 1 < L) {
				right = L - 1;
			} else if (k - 1 >= R) {
				left = R;
			} else {
				target = L;
				break;
			}
		}
		std::vector<int> ans(k);
		for (int i = 0; i < k; i++) {
			ans[i] = idx[i] - V;
		}
		return ans;
	}
};
