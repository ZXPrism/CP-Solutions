#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);

	if (n % 2 == 0) {
		for (int i = 0; i < n; i += 2) {
			v[i] = v[i + 1] = i + 1;
		}
	} else if (n >= 27) {
		v[0] = v[9] = v[25] = 1;
		v[10] = v[26] = 2;
		int val = 3;
		for (int i = 1; i < 9; i += 2) {
			v[i] = v[i + 1] = val;
			++val;
		}
		for (int i = 11; i < 25; i += 2) {
			v[i] = v[i + 1] = val;
			++val;
		}
		for (int i = 27; i < n; i += 2) {
			v[i] = v[i + 1] = val;
			++val;
		}
	} else {
		std::cout << "-1\n";
		return;
	}

	for (int i = 0; i < n; i++) {
		std::cout << v[i] << ' ';
	}
	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
