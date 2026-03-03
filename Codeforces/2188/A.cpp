#include <algorithm>
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

	// 2 n-1 1 n
	// 2 3 1 4
	// 3 n-2 2 n-1 1 n
	// 3 4 2 5 1 6
	// 3 2 4 1 5

	std::vector<int> ans(n);
	int a = n;
	int b = 1;
	for (int i = n - 1; i >= 0; i--) {
		if ((i - n + 1) % 2 == 0) {
			ans[i] = a;
			--a;
		} else {
			ans[i] = b;
			++b;
		}
	}

	for (auto elem : ans) {
		std::cout << elem << ' ';
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
