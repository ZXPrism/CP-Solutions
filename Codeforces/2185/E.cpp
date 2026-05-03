#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	int m = 0;
	int k = 0;
	std::cin >> n >> m >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> b(m);
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}

	std::sort(b.begin(), b.end());

	std::map<int, int> kill_line;
	std::map<int, std::vector<int>> another_kill_line;

	for (int i = 0; i < n; i++) {
		auto iter = std::lower_bound(b.begin(), b.end(), a[i]);
		if (iter != b.end()) {
			int k1 = *iter - a[i];
			++kill_line[k1];
			if (iter != b.begin()) {
				int k2 = *std::prev(iter) - a[i];
				++kill_line[k2];
				another_kill_line[k1].push_back(k2);
				another_kill_line[k2].push_back(k1);
			}
		} else {
			++kill_line[b.back() - a[i]];
		}
	}

	for (auto &[k1, k2_pos_vec] : another_kill_line) {
		std::sort(k2_pos_vec.begin(), k2_pos_vec.end());
	}

	std::string cmd;
	std::cin >> cmd;

	int curr = n;
	int pos = 0;
	int min_pos = 0;
	int max_pos = 0;
	for (auto ch : cmd) {
		if (ch == 'L') {
			--pos;
		} else {
			++pos;
		}

		min_pos = std::min(min_pos, pos);
		max_pos = std::max(max_pos, pos);

		auto iter = kill_line.find(pos);
		if (iter != kill_line.end()) {
			curr -= iter->second;
			auto &ano = another_kill_line[pos];
			int compensate = std::upper_bound(ano.begin(), ano.end(), max_pos) - std::lower_bound(ano.begin(), ano.end(), min_pos);
			curr += compensate;
			kill_line.erase(iter);
		}

		std::cout << curr << ' ';
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
