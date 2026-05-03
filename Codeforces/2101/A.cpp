#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<std::vector<int>> grid(n, std::vector<int>(n));
	int x = 0, y = 0, val = n * n - 1;
	int dir = 0;
	int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };
	for (int i = 0; i < n * n; i++) {
		grid[x][y] = val--;
		int nx = x + dx[dir], ny = y + dy[dir];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n && !grid[nx][ny]) {
			x = nx;
			y = ny;
		} else {
			dir = (dir + 1) % 4;
			x = x + dx[dir], y = y + dy[dir];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << grid[i][j] << ' ';
		}
		std::cout << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
