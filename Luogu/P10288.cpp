#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

// from Codeforces: @neal - https://codeforces.com/blog/entry/62393
struct custom_hash {
	static std::uint64_t splitmix64(std::uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(std::uint64_t x) const {
		static const std::uint64_t FIXED_RANDOM =
		    std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);
	std::unordered_map<int, std::vector<int>> group;
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
		group[v[i]].push_back(i);
	}

	int q = 0;
	std::cin >> q;

	int l = 0, r = 0, x = 0;
	for (int i = 0; i < q; i++) {
		std::cin >> l >> r >> x;
		--l, --r;
		std::cout << std::upper_bound(group[x].begin(), group[x].end(), r) - std::lower_bound(group[x].begin(), group[x].end(), l) << '\n';
	}
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
