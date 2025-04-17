#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	int max_len = 0;
	int left = 0;
	while (left < n) {
		int right = left + 1;
		while (right < n && v[left] == v[right]) {
			++right;
		}
		max_len = std::max(max_len, right - left);
		left = right;
	}

	std::cout << n - max_len << '\n';
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
