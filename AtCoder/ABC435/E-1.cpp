#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <ratio>
#include <set>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	int q = 0;
	std::cin >> n >> q;

	int curr = n;
	std::set<std::pair<int, int>> interval_set;
	interval_set.emplace(n, 1);
	std::vector<std::pair<int, int>> new_interval_list;

	for (int i = 0; i < q; i++) {
		int left = 0;
		int right = 0;
		std::cin >> left >> right;

		auto iter = interval_set.lower_bound({ left, -1 });
		while (iter != interval_set.end()) {
			int interval_left = iter->second;
			int interval_right = iter->first;

			if (interval_left > right) {
				break;
			} else if (interval_left < left) {
				new_interval_list.emplace_back(left - 1, interval_left);
				if (interval_right > right) {
					new_interval_list.emplace_back(interval_right, right + 1);
				}
			} else if (interval_right > right) {
				new_interval_list.emplace_back(interval_right, right + 1);
			}
			curr -= std::min(right, interval_right) - std::max(left, interval_left) + 1;

			iter = interval_set.erase(iter);
		}

		for (auto new_interval : new_interval_list) {
			interval_set.insert(new_interval);
		}
		new_interval_list.clear();

		std::cout << curr << '\n';
	}
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
