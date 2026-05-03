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
	std::string s;
	std::cin >> n >> s;

	int n_one = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			++n_one;
		}
	}

	if (n_one % 2 == 0) {
		std::cout << n_one << '\n';
		for (int i = 0; i < n; i++) {
			if (s[i] == '1') {
				std::cout << i + 1 << ' ';
			}
		}
		std::cout << '\n';
	} else {
		int n_zero = n - n_one;
		if (n_zero % 2 == 0) {
			std::cout << "-1\n";
		} else {
			std::cout << n_zero << '\n';
			for (int i = 0; i < n; i++) {
				if (s[i] == '0') {
					std::cout << i + 1 << ' ';
				}
			}
			std::cout << '\n';
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
