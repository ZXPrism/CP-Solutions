#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0, k = 0;
	std::cin >> n >> m >> k;

	std::vector<std::string> grid(n);
	for (int i = 0; i < n; i++) {
		std::cin >> grid[i];
	}

	std::vector<std::vector<int>> pre(n, std::vector<int>(m + 1));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			pre[i][j + 1] = pre[i][j] + (grid[i][j] - '0');
		}
	}

	int ans = n * m + 1;
	for (int i = 0; i < m; i++) {
		for (int j = i; j < m; j++) {
			int sum = 0;
			for (int left = 0, right = 0; right < n; right++) {
				sum += pre[right][j + 1] - pre[right][i];
				while (sum >= k) {
					ans = std::min(ans, (j - i + 1) * (right - left + 1));
					sum -= pre[left][j + 1] - pre[left][i];
					++left;
				}
			}
		}
	}

	std::cout << (ans == n * m + 1 ? 0 : ans) << '\n';
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
