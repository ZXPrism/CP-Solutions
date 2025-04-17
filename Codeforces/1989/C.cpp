#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	int va = 0, vb = 0;
	int pos = 0, neg = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == b[i]) {
			if (a[i] == 1) {
				++pos;
			} else if (a[i] == -1) {
				++neg;
			}
		} else {
			if (a[i] > b[i]) {
				va += a[i];
			} else {
				vb += b[i];
			}
		}
	}

	int ans = std::numeric_limits<int>::min();
	for (int i = -neg; i <= pos; i++) {
		ans = std::max(ans, std::min(va + i, vb + pos - neg - i));
	}
	std::cout << ans << '\n';
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
