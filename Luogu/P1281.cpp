#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int m = 0;
	int k = 0;
	std::cin >> m >> k;

	std::vector<int> v(m);
	for (int i = 0; i < m; i++) {
		std::cin >> v[i];
	}
	int total = std::accumulate(v.begin(), v.end(), 0);

	auto check = [&](int max_pages) -> bool {
		int cnt = 0;
		int left = 0;
		while (left < m) {
			int curr = v[left];
			int right = left + 1;
			while (right < m && curr + v[right] <= max_pages) {
				curr += v[right];
				right++;
			}
			cnt++;
			left = right;
		}
		return cnt <= k;
	};

	int left = *std::max_element(v.begin(), v.end()) - 1;
	int right = total + 1;
	int mid = 0;
	while (left + 1 < right) {
		mid = (left + right) >> 1;
		if (check(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}

	// construct using right
	int max_pages = right;
	std::vector<std::pair<int, int>> ans;
	right = m - 1;
	while (right >= 0) {
		int curr = v[right];
		int left = right - 1;
		while (left >= 0 && curr + v[left] <= max_pages) {
			curr += v[left];
			left--;
		}
		ans.emplace_back(left + 2, right + 1);
		right = left;
	}

	int n = ans.size();
	for (int i = 0; i < k - n; i++) {
		std::cout << "0 0\n";
	}
	for (int i = n - 1; i >= 0; i--) {
		auto [u, v] = ans[i];
		std::cout << u << ' ' << v << '\n';
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
