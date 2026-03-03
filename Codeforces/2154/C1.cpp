#include <iostream>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

constexpr int MAX_A = 200005;
std::vector<int> factor[MAX_A];

void preprocess() {
	for (int i = 2; i < MAX_A; i++) {
		for (int j = i; j < MAX_A; j += i) {
			factor[j].push_back(i);
		}
	}
}

void solve() {
	int n = 0;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	std::vector<int> exist(MAX_A);
	for (int i = 0; i < n; i++) {
		for (auto fac : factor[a[i]]) {
			if (exist[fac] != 0) {
				std::cout << "0\n";
				return;
			}
			exist[fac]++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (auto fac : factor[a[i]]) {
			exist[fac]--;
		}
		for (auto fac : factor[a[i] + 1]) {
			if (exist[fac] != 0) {
				std::cout << "1\n";
				return;
			}
		}
		for (auto fac : factor[a[i]]) {
			exist[fac]++;
		}
	}

	std::cout << "2\n";
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
