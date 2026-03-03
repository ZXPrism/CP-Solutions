#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	std::string s1;
	std::string s2;
	std::cin >> n >> s1 >> s2;
	std::multiset<char> mset_1;
	std::multiset<char> mset_2;
	for (auto ch : s1) {
		mset_1.insert(ch);
	}
	for (auto ch : s2) {
		mset_2.insert(ch);
	}
	std::cout << ((mset_1 == mset_2) ? "YES\n" : "NO\n");
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
