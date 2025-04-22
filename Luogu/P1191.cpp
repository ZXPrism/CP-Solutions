#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<std::string> grid(n);
	for (int i = 0; i < n; i++) {
		std::cin >> grid[i];
	}

	i64 ans = 0;

	std::vector<int> heights(n + 1);
	heights[n] = -1;

	for (int i = 0; i < n; i++) {
		std::stack<int> st;
		st.push(-1);
		for (int j = 0; j < n; j++) {
			heights[j] = (grid[i][j] == 'W' ? heights[j] + 1 : 0);
		}
		for (int j = 0; j <= n; j++) {
			while (st.size() != 1 && heights[j] <= heights[st.top()]) {
				int mid = st.top();
				st.pop();
				ans += 1LL * heights[mid] * (j - mid) * (mid - st.top());
			}
			st.push(j);
		}
	}

	std::cout << ans << '\n';
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
