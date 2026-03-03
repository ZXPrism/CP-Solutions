#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	constexpr int MAXN = 2000'00;
	std::vector<int> cnt(MAXN + 2);
	for (int i = 0; i < n; i++) {
		++cnt[0];
		--cnt[v[i]];
	}

	for (int i = 1; i <= MAXN; i++) {
		cnt[i] += cnt[i - 1];
	}

	for (int i = 0; i <= MAXN; i++) {
		int carry = cnt[i] / 10;
		int residue = cnt[i] - carry * 10;
		cnt[i + 1] += carry;
		cnt[i] = residue;
	}

	for (int i = MAXN + 1; i >= 0; i--) {
		if (cnt[i] != 0) {
			for (int j = i; j >= 0; j--) {
				std::cout << cnt[j];
			}
			break;
		}
	}

	std::cout << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	preprocess();

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
