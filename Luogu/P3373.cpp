#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

std::vector<int> input;
i64 data[100005 * 4];
i64 tag_add[100005 * 4];
i64 tag_mul[100005 * 4];
int modulo;

void build() {
	int n = input.size();
	auto init = [&](this auto &&init, int left, int right, int id) {
		if (left == right) {
			data[id] = input[left] % modulo;
			return;
		}
		int mid = (left + right) / 2;
		init(left, mid, id * 2);
		init(mid + 1, right, (id * 2) + 1);
		data[id] = data[id * 2] + data[(id * 2) + 1];
		tag_mul[id] = 1;
		tag_add[id] = 0;
	};
	init(0, n - 1, 1);
}

void pushdown(int left, int right, int id) {
	if ((tag_add[id] != 0 || tag_mul[id] != 1) && left != right) {
		int mid = (left + right) / 2;

		data[id * 2] = (data[id * 2] * tag_mul[id]) % modulo;
		data[(id * 2) + 1] = (data[(id * 2) + 1] * tag_mul[id]) % modulo;
		tag_mul[id * 2] = (tag_mul[id * 2] * tag_mul[id]) % modulo;
		tag_mul[(id * 2) + 1] = (tag_mul[(id * 2) + 1] * tag_mul[id]) % modulo;
		tag_add[id * 2] = (tag_add[id * 2] * tag_mul[id]) % modulo;
		tag_add[(id * 2) + 1] = (tag_add[(id * 2) + 1] * tag_mul[id]) % modulo;
		tag_mul[id] = 1;

		data[id * 2] = (data[id * 2] + (tag_add[id] * (mid + 1 - left))) % modulo;
		data[(id * 2) + 1] = (data[(id * 2) + 1] + (tag_add[id] * (right - mid))) % modulo;
		tag_add[id * 2] = (tag_add[id * 2] + tag_add[id]) % modulo;
		tag_add[(id * 2) + 1] = (tag_add[(id * 2) + 1] + tag_add[id]) % modulo;
		tag_add[id] = 0;
	}
}

i64 query(int qleft, int qright, int left, int right, int id) {
	if (qleft <= left && right <= qright) {
		return data[id] % modulo;
	}
	pushdown(left, right, id);
	int mid = (left + right) / 2;
	i64 res = 0;
	if (qleft <= mid) {
		res = (res + query(qleft, qright, left, mid, id * 2)) % modulo;
	}
	if (qright > mid) {
		res = (res + query(qleft, qright, mid + 1, right, (id * 2) + 1)) % modulo;
	}
	return res;
}

void add(int qleft, int qright, int qk, int left, int right, int id) {
	if (qleft <= left && right <= qright) {
		data[id] = (data[id] + (1LL * qk * (right - left + 1))) % modulo;
		tag_add[id] = (tag_add[id] + qk) % modulo;
		return;
	}
	pushdown(left, right, id);
	int mid = (left + right) / 2;
	if (qleft <= mid) {
		add(qleft, qright, qk, left, mid, id * 2);
	}
	if (qright > mid) {
		add(qleft, qright, qk, mid + 1, right, (id * 2) + 1);
	}
	data[id] = (data[id * 2] + data[(id * 2) + 1]) % modulo;
}

void mul(int qleft, int qright, int qk, int left, int right, int id) {
	if (qleft <= left && right <= qright) {
		data[id] = (data[id] * qk) % modulo;
		tag_mul[id] = (tag_mul[id] * qk) % modulo;
		tag_add[id] = (tag_add[id] * qk) % modulo;
		return;
	}
	pushdown(left, right, id);
	int mid = (left + right) / 2;
	if (qleft <= mid) {
		mul(qleft, qright, qk, left, mid, id * 2);
	}
	if (qright > mid) {
		mul(qleft, qright, qk, mid + 1, right, (id * 2) + 1);
	}
	data[id] = (data[id * 2] + data[(id * 2) + 1]) % modulo;
}

void preprocess() {
}

void solve() {
	int n = 0;
	int q = 0;
	std::cin >> n >> q >> modulo;

	input = std::vector<int>(n);
	for (int i = 0; i < n; i++) {
		std::cin >> input[i];
	}

	build();

	for (int i = 0; i < q; i++) {
		int op = 0;
		int x = 0;
		int y = 0;
		int k = 0;
		std::cin >> op;

		if (op == 1) {  // mul k to [x, y]
			std::cin >> x >> y >> k;
			--x;
			--y;
			mul(x, y, k, 0, n - 1, 1);
		} else if (op == 2) {  // add k to [x, y]
			std::cin >> x >> y >> k;
			--x;
			--y;
			add(x, y, k, 0, n - 1, 1);
		} else {  // output [x, y] sum % m
			std::cin >> x >> y;
			--x;
			--y;
			std::cout << query(x, y, 0, n - 1, 1) << '\n';
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
