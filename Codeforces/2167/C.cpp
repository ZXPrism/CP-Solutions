#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	int odd = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] & 1) {
			++odd;
		}
	}

	if (odd != 0 && odd != n) {
		std::sort(v.begin(), v.end());
	}
	for (int i = 0; i < n; i++) {
		std::cout << v[i] << " \n"[i == n - 1];
	}
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
