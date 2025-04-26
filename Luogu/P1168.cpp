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

	std::priority_queue<int> left;
	std::priority_queue<int, std::vector<int>, std::greater<>> right;
	std::vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		if (left.size() == right.size()) {
			left.push(v[i]);
			right.push(left.top());
			left.pop();
		} else {
			right.push(v[i]);
			left.push(right.top());
			right.pop();
		}
		if (~i & 1) {
			ans[i] = right.top();
		}
	}

	for (int i = 0; i < n; i++) {
		if (~i & 1) {
			std::cout << ans[i] << '\n';
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
