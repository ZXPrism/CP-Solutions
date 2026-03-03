#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

constexpr int MAX_V = 2000'05;

std::vector<int> prime_factor_list[MAX_V];

void preprocess() {
	for (int i = 2; i < MAX_V; i++) {
		if (prime_factor_list[i].empty()) {
			for (int j = i; j < MAX_V; j += i) {
				prime_factor_list[j].push_back(i);
			}
		}
	}
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> cnt(MAX_V);
	for (int i = 0; i < n; i++) {
		for (auto fac : prime_factor_list[a[i]]) {
			if (cnt[fac] != 0) {
				std::cout << "0\n";
				return;
			}
			++cnt[fac];
		}
	}

	i64 ans = std::numeric_limits<i64>::max();

	for (int i = 0; i < n; i++) {
		for (auto fac : prime_factor_list[a[i]]) {
			--cnt[fac];
		}
		for (auto fac : prime_factor_list[a[i] + 1]) {
			if (cnt[fac] != 0) {
				ans = std::min(ans, 1LL * b[i]);
				break;
			}
		}
		for (auto fac : prime_factor_list[a[i]]) {
			++cnt[fac];
		}
	}

	// find the one has least bi
	int min_bi_idx = std::min_element(b.begin(), b.end()) - b.begin();

	// 1. only modify one element
	for (auto fac : prime_factor_list[a[min_bi_idx]]) {
		--cnt[fac];
	}

	// k = (mp - a) > 0
	// mp > a
	// m >= ceil(a / p)
	// k = ceil(a / p) * p - a
	for (int j = 2; j < MAX_V; j++) {
		if (cnt[j] != 0) {
			ans = std::min(ans, 1LL * ((a[min_bi_idx] + j - 1) / j * j - a[min_bi_idx]) * b[min_bi_idx]);
		}
	}

	// 2. modify two elements
	std::vector<int> odd;
	for (int i = 0; i < n; i++) {
		if (a[i] & 1) {
			odd.push_back(b[i]);
		}
	}
	if (odd.size() >= 2) {
		std::sort(odd.begin(), odd.end());
		ans = std::min(ans, 1LL * odd[0] + odd[1]);
	}

	std::cout << ans << '\n';
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
