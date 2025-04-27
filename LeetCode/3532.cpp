class DSU {
private:
	std::vector<int> _Parent;

public:
	explicit DSU(size_t n) { _Parent = std::vector<int>(n + 1, -1); }

	int Find(int x) {
		int root = x;
		while (_Parent[root] >= 0) {
			root = _Parent[root];
		}
		while (_Parent[x] >= 0) {
			int y = _Parent[x];
			_Parent[x] = root;
			x = y;
		}
		return root;
	}

	void Merge(int from, int to) {
		from = Find(from);
		to = Find(to);
		if (from != to) {
			_Parent[to] += _Parent[from];
			_Parent[from] = to;
		}
	}
};

class Solution {
public:
	vector<bool> pathExistenceQueries(int n, vector<int> &nums, int maxDiff,
	                                  vector<vector<int>> &queries) {

		DSU dsu(n);
		for (int i = 1; i < n; i++) {
			if (nums[i] - nums[i - 1] <= maxDiff) {
				dsu.Merge(i - 1, i);
			}
		}

		int q = queries.size();
		std::vector<bool> ans(q);
		for (int i = 0; auto &query : queries) {
			if (dsu.Find(query[0]) == dsu.Find(query[1])) {
				ans[i] = true;
			}
			++i;
		}

		return ans;
	}
};
