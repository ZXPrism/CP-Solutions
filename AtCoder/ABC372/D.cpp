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

	std::vector<int> ans(n);
	std::stack<int> st;
	for (int i = n - 1; i >= 0; i--) {
		ans[i] = st.size();
		while (!st.empty() && v[i] > st.top()) {
			st.pop();
		}
		st.push(v[i]);
	}

	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " \n"[i == n - 1];
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}
