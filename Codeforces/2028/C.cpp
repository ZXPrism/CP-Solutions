#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0, v = 0;
	std::cin >> n >> m >> v;

	std::vector<int> arr(n);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::vector<int> pre(n + 1);
	std::vector<i64> pre_sum(n + 1);
	int cnt = 0;
	i64 sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum >= v) {
			sum = 0;
			++cnt;
		}
		pre[i + 1] = cnt;
		pre_sum[i + 1] = pre_sum[i] + arr[i];
	}

	if (cnt < m) {
		std::cout << "-1\n";
		return;
	}

	std::vector<int> suf(n + 2);
	sum = 0;
	cnt = 0;
	for (int i = n - 1; i >= 0; i--) {
		sum += arr[i];
		if (sum >= v) {
			sum = 0;
			++cnt;
		}
		suf[i + 1] = cnt;
	}

	i64 ans = 0;
	for (int left = 0, right = 0; right < n; right++) {
		while (pre[left] + suf[right + 2] < m) {
			++left;
		}
		ans = std::max(ans, pre_sum[right + 1] - pre_sum[left]);
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
