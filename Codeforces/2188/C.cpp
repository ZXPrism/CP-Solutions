#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	if (std::is_sorted(a.begin(), a.end())) {
		std::cout << "-1\n";
		return;
	}

	auto b = a;
	std::sort(b.begin(), b.end());
	int mi = b.front();
	int mx = b.back();

	int k = std::numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) {
			k = std::min(k, std::max(a[i] - mi, mx - a[i]));
		}
	}

	std::cout << k << '\n';
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
