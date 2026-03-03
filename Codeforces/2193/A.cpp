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
	int n = 0;
	int s = 0;
	int x = 0;
	std::cin >> n >> s >> x;

	int sum = 0;
	for (int i = 0; i < n; i++) {
		int t = 0;
		std::cin >> t;
		sum += t;
	}

	int delta = s - sum;
	if (delta >= 0 && delta % x == 0) {
		std::cout << "YES\n";
	} else {
		std::cout << "NO\n";
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
