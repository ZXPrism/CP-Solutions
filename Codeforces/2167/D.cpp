#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

constexpr int MAX_V = 10000;

std::vector<int> not_prime(MAX_V);
std::vector<int> prime_list;

void preprocess() {
	for (int i = 2; i < MAX_V; i++) {
		if (not_prime[i] == 0) {
			prime_list.push_back(i);
		}
		for (auto prime : prime_list) {
			i64 x = 1LL * prime * i;
			if (x >= MAX_V) {
				break;
			}
			not_prime[x] = 1;
			if (i % prime == 0) {
				break;
			}
		}
	}
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<i64> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	i64 ans = MAX_V;
	for (int i = 0; i < n; i++) {
		for (auto prime : prime_list) {
			if (v[i] % prime != 0) {
				ans = std::min(ans, 1LL * prime);
				break;
			}
		}
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
