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

	bool ok = false;
	int seg = 0;
	int left = 0;
	while (left < n) {
		int right = left + 1;
		while (right < n && s[right] == s[left]) {
			++right;
		}
		++seg;
		if (right - left > 1) {
			ok = true;
		}
		left = right;
	}

	if (seg == 1) {
		std::cout << "1\n";
		return;
	}

	if (s.front() == s.back()) {
		--seg;
		ok = true;
	}

	if (ok) {
		std::cout << seg + 1 << '\n';
	} else {
		std::cout << seg << '\n';
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
