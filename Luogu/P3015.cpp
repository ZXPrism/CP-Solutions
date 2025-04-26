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

	constexpr i64 P = 12345678910;
	std::stack<i64> st;
	std::stack<int> st_cnt;
	st.push(0);
	st_cnt.push(0);

	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			st.push(0);
			st_cnt.push(1);
		} else {
			i64 top = st.top();
			st.pop();

			int cnt = st_cnt.top();
			st_cnt.pop();

			st.top() = (st.top() + (cnt == 1 ? 1 : top * 2)) % P;
			st_cnt.top() += cnt;
		}
	}

	std::cout << st.top() << '\n';
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
