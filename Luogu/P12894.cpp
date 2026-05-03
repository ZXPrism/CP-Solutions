#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

template<typename T>
class Fenwick {
private:
	std::vector<T> _Data;
	int _N;

public:
	Fenwick(int n)
	    : _N(n) {
		_Data.resize(n + 1);
	}

	void add(int idx, T k) {
		while (idx <= _N) {
			_Data[idx] += k;
			idx += idx & -idx;
		}
	}

	T qry(int idx) {
		T res{};
		while (idx) {
			res += _Data[idx];
			idx &= idx - 1;
		}
		return res;
	}

	T qry_rng(int left, int right) {
		return qry(right) - qry(left - 1);
	}
};

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	Fenwick<int> f1(n), f2(n), fx(n);
	for (int i = 0; i < n; i++) {
		if (v[i] == 1) {
			f1.add(i + 1, 1);
		} else if (v[i] == 2) {
			f2.add(i + 1, 1);
		} else {
			fx.add(i + 1, 1);
		}
	}

	int type = 0, opa = 0, opb = 0;
	for (int i = 0; i < m; i++) {
		std::cin >> type >> opa >> opb;

		if (type == 1) {
			i64 c1 = f1.qry_rng(opa, opb);
			i64 c2 = f2.qry_rng(opa, opb);
			i64 cx = fx.qry_rng(opa, opb);
			std::cout << c1 * (c1 - 1) + 3 * c1 * c2 + 2 * c1 * cx + c2 * (c2 - 1) / 2 + c2 * cx + cx * (cx - 1) / 2 << '\n';
		} else if (v[opa - 1] != opb) {
			if (v[opa - 1] == 1) {
				f1.add(opa, -1);
			} else if (v[opa - 1] == 2) {
				f2.add(opa, -1);
			} else {
				fx.add(opa, -1);
			}
			v[opa - 1] = opb;
			if (opb == 1) {
				f1.add(opa, 1);
			} else if (opb == 2) {
				f2.add(opa, 1);
			} else {
				fx.add(opa, 1);
			}
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
