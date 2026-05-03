#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	int h = 0;
	int k = 0;
	std::cin >> n >> h >> k;

	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<i64> pre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + a[i];
	}
	auto sum = pre[n];

	auto n_full_rounds = h / sum;
	auto remain_hp = h - (n_full_rounds * sum);
	if (remain_hp == 0) {
		std::cout << (n_full_rounds * n) + (n_full_rounds - 1) * k << '\n';
	} else {
		auto ans_full_rounds = n_full_rounds * (n + k);

		auto par = std::lower_bound(pre.begin(), pre.end(), remain_hp) - pre.begin();
		if (par == 1) {
			std::cout << ans_full_rounds + 1 << '\n';
		} else {
			auto candidate = ans_full_rounds + par;

			std::vector<i64> suf_max(n + 1);
			suf_max[n] = a[n - 1];
			for (int i = n - 1; i >= 1; i--) {
				suf_max[i] = std::max(suf_max[i + 1], a[i - 1]);
			}

			auto pre_min = a[0];
			for (int i = 1; i < par; i++) {
				pre_min = std::min(pre_min, a[i - 1]);
				auto curr = pre[i] - pre_min + suf_max[i + 1];
				if (curr >= remain_hp) {
					std::cout << ans_full_rounds + i << '\n';
					return;
				}
			}
			std::cout << candidate << '\n';
		}
	}
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
