#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	int q = 0;
	std::cin >> n >> q;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	const int sqrtn = static_cast<int>(std::sqrt(static_cast<double>(n)));

	std::vector<std::vector<std::vector<i64>>> pre(sqrtn);
	std::vector<std::vector<std::vector<i64>>> pre_dot(sqrtn);
	for (int d = 1; d < sqrtn; d++) {
		const int length = (n + d - 1) / d;
		pre[d] = std::vector<std::vector<i64>>(d + 1, std::vector<i64>(length + 1));
		pre_dot[d] = std::vector<std::vector<i64>>(d + 1, std::vector<i64>(length + 1));
		for (int start = 1; start <= d; start++) {
			for (int i = start, j = 0; i <= n; i += d, j++) {
				pre[d][start][j + 1] = pre[d][start][j] + a[i];
				pre_dot[d][start][j + 1] = pre_dot[d][start][j] + 1LL * (j + 1) * a[i];
			}
		}
	}

	for (int _ = 0; _ < q; _++) {
		int s = 0;
		int d = 0;
		int k = 0;
		std::cin >> s >> d >> k;

		if (d >= sqrtn) {
			i64 res = 0;
			for (int i = 1; i <= k; i++) {
				res += 1LL * i * a[s + d * (i - 1)];
			}
			std::cout << res << ' ';
		} else {
			int r = s % d;
			if (r == 0) {
				r = d;
			}
			int left = (s - 1) / d + 1;
			int right = left + k - 1;
			i64 t1 = pre_dot[d][r][right] - pre_dot[d][r][left - 1];
			i64 t2 = (left - 1) * (pre[d][r][right] - pre[d][r][left - 1]);
			std::cout << t1 - t2 << ' ';
		}
	}

	std::cout << '\n';
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
