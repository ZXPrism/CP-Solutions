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
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	std::cin >> a >> b >> c >> d;
	if (a == b && b == c && c == d) {
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
