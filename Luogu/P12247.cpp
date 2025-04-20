#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0, k = 0;
	std::cin >> n >> m >> k;

	std::vector<int> l(n), r(n), w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> l[i] >> r[i] >> w[i];
	}

	struct Event {
		int w;
		int state;
	};

	std::vector<std::vector<Event>> events(m + 2);
	for (int i = 0; i < n; i++) {
		l[i] += k - 1;
		if (l[i] <= r[i]) {
			events[l[i]].emplace_back(w[i], 1);
			events[r[i] + 1].emplace_back(w[i], -1);
		}
	}

	std::multiset<int> ms;
	std::vector<i64> dp(m + 1);
	for (int i = 1; i <= m; i++) {
		for (auto &ev : events[i]) {
			if (ev.state == 1) {
				ms.insert(ev.w);
			} else {
				ms.erase(ms.find(ev.w));
			}
		}
		dp[i] = dp[i - 1];
		if (!ms.empty()) {
			dp[i] = std::max(dp[i], dp[i - k] + *ms.rbegin());
		}
	}

	std::cout << dp[m] << '\n';
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
