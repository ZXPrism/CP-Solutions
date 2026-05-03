#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	i64 n = 0;
	std::cin >> n;

	if (n == 1) {
		std::cout << "2\n";
	} else if (n == 2) {
		std::cout << "6\n";
	} else {
		constexpr int P = 998'244'353;
		i64 mat[] = { 1, 1, 1, 0 };
		i64 res[] = { 1, 0, 0, 1 };
		i64 x = n - 2;

		auto mat_mul = [](i64 lhs[4], i64 rhs[4]) {
			std::tie(lhs[0], lhs[1], lhs[2], lhs[3]) =
			    std::make_tuple((lhs[0] * rhs[0] + lhs[1] * rhs[2]) % (P - 1),
			                    (lhs[0] * rhs[1] + lhs[1] * rhs[3]) % (P - 1),
			                    (lhs[2] * rhs[0] + lhs[3] * rhs[2]) % (P - 1),
			                    (lhs[2] * rhs[1] + lhs[3] * rhs[3]) % (P - 1));
		};

		while (x) {
			if (x & 1) {
				mat_mul(res, mat);
			}
			mat_mul(mat, mat);
			x >>= 1;
		}

		i64 an = (res[0] + res[1]) % (P - 1);
		i64 an_1 = (res[2] + res[3]) % (P - 1);

		auto fast_pow = [](i64 a, i64 b) -> i64 {
			i64 res = 1;
			while (b) {
				if (b & 1) {
					res = (res * a) % P;
				}
				a = (a * a) % P;
				b >>= 1;
			}
			return res;
		};

		std::cout << (fast_pow(6, an) * fast_pow(3, (an_1 + P - 2) % (P - 1))) % P << '\n';
	}
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
