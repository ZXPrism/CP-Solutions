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
	// CODEFORCES GET HACKED?
	// HELLO HACKER!

	// given a sorted array a
	// target: a[0] + a[1] > a[-1], i.e. sum of 2-smallest elements > the largest element
	// each time, assign one element to anther element, then resort the array
	// find the minimum number of ops (<=n-1)
	int n = 0;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::sort(a.begin(), a.end());

	// 1, 1, 2, 2, 3, 3, 4, 4, 5, 6, 7, 8, 8, 9, 9
	// each op shrinks & expands one equal range
	// 1 1 | 2 2 | 3 3 | 4 4 | 5 | 6 | 7 | 8 8 | 9 9
	// but how can I connect it with optimality (minimum)? this is the crux!
	// think about the compulsory moves
	// we want to reach some states, that sum of 2-smallest elements > the largest element
	// essentially, remove some prefix and some suffix to reach that state, and the number of removed elements are minimized
	// or, find the longest valid subarray (length at least 3)
	// this is a classic sliding window problem
	int res = 0;
	for (int left = 0, right = 0; right < n; right++) {
		while (right - left + 1 >= 3 && a[left] + a[left + 1] <= a[right]) {
			++left;
		}
		if (right - left + 1 >= 3) {
			res = std::max(res, right - left + 1);
		}
	}

	std::cout << std::min(n - 2, n - res) << '\n';
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
