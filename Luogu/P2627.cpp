#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, k = 0;
	std::cin >> n >> k;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	std::vector<i64> pre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + v[i];
	}

	std::vector<i64> dp(n + 2);
	std::deque<i64> deq;
	deq.push_back(-1);
	for (int i = 0; i < n; i++) {
		while (!deq.empty() && deq.front() < std::max(-1, i - k)) {
			deq.pop_front();
		}
		dp[i + 2] = std::max(dp[i + 1], pre[i + 1] + dp[deq.front() + 1] - pre[deq.front() + 1]);
		i64 curr = dp[i + 1] - pre[i + 1];
		while (!deq.empty() && curr >= dp[deq.back() + 1] - pre[deq.back() + 1]) {
			deq.pop_back();
		}
		deq.push_back(i);
	}

	std::cout << dp[n + 1] << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	solve();

	return 0;
}
