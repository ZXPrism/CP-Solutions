#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	const int segment_length = static_cast<int>(std::sqrt(n));
	auto managed = v;
	for (int start = 0; start < n; start += segment_length) {
		if (start + segment_length <= n) {
			std::sort(managed.begin() + start, managed.begin() + start + segment_length);
		} else {
			std::sort(managed.begin() + start, managed.end());
		}
	}

	int q = 0;
	std::cin >> q;

	for (int i = 0; i < q; i++) {
		int type = 0;
		std::cin >> type;
		if (type == 0) {
			int a = 0;
			int b = 0;
			int c = 0;
			std::cin >> a >> b >> c;

			--a;
			--b;

			int start_block = a / segment_length;
			int end_block = b / segment_length;

			int curr = 0;
			if (start_block == end_block) {
				for (int i = a; i <= b; i++) {
					curr += static_cast<int>(v[i] >= c);
				}
			} else {
				int start_block_end_idx = start_block * segment_length + segment_length - 1;
				for (int i = a; i <= start_block_end_idx; i++) {
					curr += static_cast<int>(v[i] >= c);
				}
				for (int block = start_block + 1; block < end_block; block++) {
					curr += block * segment_length + segment_length - (std::lower_bound(managed.begin() + block * segment_length, managed.begin() + block * segment_length + segment_length, c) - managed.begin());
				}
				int end_block_start_idx = end_block * segment_length;
				for (int i = end_block_start_idx; i <= b; i++) {
					curr += static_cast<int>(v[i] >= c);
				}
			}

			std::cout << curr << '\n';
		} else {
			int a = 0;
			int b = 0;
			std::cin >> a >> b;
			--a;
			v[a] = b;
			int block = a / segment_length;
			int start = block * segment_length;
			int end = std::min(block * segment_length + segment_length, n);
			std::copy(v.begin() + start, v.begin() + end, managed.begin() + start);
			std::sort(managed.begin() + start, managed.begin() + end);
		}
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
