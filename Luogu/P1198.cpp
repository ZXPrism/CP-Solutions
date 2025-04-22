#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

template<typename T>
class SegmentTree {
public:
	SegmentTree(size_t N)
	    : _N(N) {
		_Data = std::vector<T>(_N << 2);
		_Tag = std::vector<T>(_N << 2);
	}

	explicit SegmentTree(const std::vector<T> &vec)
	    : _N(vec.size()) {
		_Data = std::vector<T>(_N << 2);
		_Tag = std::vector<T>(_N << 2);
		_BuildTree(vec, 1, _N, 1);
	}

	void Add(int left, int right, T value) {
		return _Add(left, right, value, 1, _N, 1);
	}

	T Query(int left, int right) {
		return _Query(left, right, 1, _N, 1);
	}

private:
	void _BuildTree(const std::vector<T> &vec, int left, int right, int id) {
		if (left == right) {
			_Data[id] = vec[left - 1];
			return;
		}

		int mid = (left + right) >> 1;
		_BuildTree(vec, left, mid, id << 1);
		_BuildTree(vec, mid + 1, right, (id << 1) + 1);

		_Data[id] = std::max(_Data[id << 1], _Data[(id << 1) + 1]);
	}

	void _Add(int left, int right, T value, int segLeft, int segRight, int id) {
		if (left <= segLeft && segRight <= right) {
			_Data[id] += value;
			_Tag[id] += value;
			return;
		}

		_PushDown(segLeft, segRight, id);

		int mid = (segLeft + segRight) >> 1;
		if (left <= mid) {
			_Add(left, right, value, segLeft, mid, id << 1);
		}
		if (right > mid) {
			_Add(left, right, value, mid + 1, segRight, (id << 1) + 1);
		}

		_Data[id] = std::max(_Data[id << 1], _Data[(id << 1) + 1]);
	}

	T _Query(int left, int right, int segLeft, int segRight, int id) {
		if (left <= segLeft && segRight <= right) {
			return _Data[id];
		}

		_PushDown(segLeft, segRight, id);

		T ans = std::numeric_limits<T>::min();
		int mid = (segLeft + segRight) >> 1;
		if (left <= mid) {
			ans = std::max(ans, _Query(left, right, segLeft, mid, id << 1));
		}
		if (right > mid) {
			ans = std::max(ans, _Query(left, right, mid + 1, segRight, (id << 1) + 1));
		}

		return ans;
	}

	void _PushDown(int left, int right, int id) {
		if (_Tag[id] && left != right) {
			_Tag[id << 1] += _Tag[id];
			_Tag[(id << 1) + 1] += _Tag[id];
			_Data[id << 1] += _Tag[id];
			_Data[(id << 1) + 1] += _Tag[id];
			_Tag[id] = 0;
		}
	}

private:
	size_t _N = 0;
	std::vector<T> _Data, _Tag;
};

void solve() {
	int m = 0, d = 0;
	std::cin >> m >> d;

	SegmentTree<int> seg_tree(m);
	int prev = 0, len = 1;
	for (int i = 0; i < m; i++) {
		char type = 0;
		i64 val = 0;
		std::cin >> type >> val;
		if (type == 'A') {
			val = (val + prev) % d;
			seg_tree.Add(len, len, val);
			++len;
		} else if (type == 'Q') {
			prev = seg_tree.Query(len - val, len);
			std::cout << prev << '\n';
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
