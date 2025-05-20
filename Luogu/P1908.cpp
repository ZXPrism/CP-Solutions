#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	i64 ans = 0;
	std::vector<int> aux(n);
	auto Merge = [&](int left, int right) -> void {
		int mid = (left + right) >> 1;
		int i = left, j = mid + 1, k = 0;
		while (i <= mid && j <= right) {
			if (v[i] <= v[j]) {
				aux[k++] = v[i];
				++i;
			} else {
				aux[k++] = v[j];
				ans += mid + 1 - i;
				++j;
			}
		}
		while (i <= mid) {
			aux[k++] = v[i];
			++i;
		}
		while (j <= right) {
			aux[k++] = v[j];
			++j;
		}
		std::copy(aux.begin(), aux.begin() + k, v.begin() + left);
	};
	auto MergeSort = [&](auto &&self, int left, int right) -> void {
		if (left < right) {
			int mid = (left + right) >> 1;
			self(self, left, mid);
			self(self, mid + 1, right);
			Merge(left, right);
		}
	};
	MergeSort(MergeSort, 0, n - 1);

	std::cout << ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
