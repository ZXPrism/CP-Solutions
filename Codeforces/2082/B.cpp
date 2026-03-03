#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int x = 0;
	int n = 0;
	int m = 0;
	std::cin >> x >> n >> m;

	auto floor = [](int val, int max_op) -> int {
		while (val && max_op) {
			val >>= 1;
			--max_op;
		}
		return val;
	};

	auto ceil = [](int val, int max_op) -> int {
		while (val > 1 && max_op) {
			val = (val + 1) >> 1;
			--max_op;
		}
		return val;
	};

	std::cout << floor(ceil(x, m), n) << ' ' << ceil(floor(x, n), m) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	preprocess();

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
