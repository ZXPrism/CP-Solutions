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
	int l = 0;
	int a = 0;
	int b = 0;

	std::cin >> l >> a >> b;

	int ans = a;
	std::vector<int> visited(l);
	while (visited[a] == 0) {
		visited[a] = 1;
		ans = std::max(ans, a);
		a = (a + b) % l;
	}

	std::cout << ans << '\n';
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
