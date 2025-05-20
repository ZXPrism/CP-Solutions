constexpr int N = 1'000'00;
std::vector<int> fac[N + 1];

auto init = []() -> int {
	for (int i = 2; i <= N; i++) {
		if (fac[i].empty()) {
			for (int j = i; j <= N; j += i) {
				fac[j].push_back(i);
			}
		}
	}
	return 0;
}();

class Solution {
public:
	bool canTraverseAllPairs(vector<int> &nums) {
		int n = nums.size();
		int mx = *std::ranges::max_element(nums);

		std::vector<int> fa(n + mx + 1, -1);
		auto Find = [&](int x) -> int {
			int root = x;
			while (fa[root] >= 0) {
				root = fa[root];
			}
			while (fa[x] >= 0) {
				int y = fa[x];
				fa[x] = root;
				x = y;
			}
			return root;
		};
		auto Unite = [&](int from, int to) -> void {
			from = Find(from);
			to = Find(to);
			if (from != to) {
				fa[from] = to;
			}
		};

		for (int i = 0; i < n; i++) {
			for (auto factor : fac[nums[i]]) {
				Unite(i, n + factor);
			}
		}

		int root = Find(0);
		for (int i = 1; i < n; i++) {
			if (Find(i) != root) {
				return false;
			}
		}

		return true;
	}
};
