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
	int d = 0;
	std::cin >> n >> d;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	i64 ans = 0;
	std::multiset<int> tracked;

	auto check = [&](int x) -> bool {
		if (tracked.empty()) {
			return true;
		}
		auto cand = tracked.lower_bound(x);
		if (cand == tracked.begin()) {
			return *cand - x >= d;
		}
		auto prev = std::prev(cand);
		int diff = x - *prev;
		if (cand != tracked.end()) {
			diff = std::min(diff, *cand - x);
		}
		return diff >= d;
	};

	for (int left = 0, right = 0; right < n; right++) {
		while (!check(v[right])) {
			tracked.erase(v[left]);
			++left;
		}
		tracked.insert(v[right]);
		ans += right - left + 1;
	}

	std::cout << ans << '\n';
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
