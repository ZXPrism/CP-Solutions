#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int ans = n + (s[0] == '1');
	for (int i = 1; i < n; i++) {
		if (s[i] != s[i - 1]) {
			++ans;
		}
	}

	int cnt = 0;
	int left = 0;
	while (left < n) {
		int right = left + 1;
		while (right < n && s[left] == s[right]) {
			++right;
		}
		left = right;
		++cnt;
	}

	if (cnt >= 4) {
		ans -= 2;
	} else if (cnt == 3) {
		if (s[0] == '1') {
			ans -= 2;
		} else {
			--ans;
		}
	} else if (cnt == 2 && s[0] == '1') {
		--ans;
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
