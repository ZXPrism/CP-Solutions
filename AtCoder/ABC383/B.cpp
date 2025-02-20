#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int h = 0, w = 0, d = 0;
    std::cin >> h >> w >> d;

    std::vector<std::string> grid(h);
    for (int i = 0; i < h; i++) {
        std::cin >> grid[i];
    }

    std::vector<std::pair<int, int>> floor;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '.') {
                floor.push_back({i, j});
            }
        }
    }

    auto F = [](int a, int b, int x, int y) -> int { return std::abs(a - x) + std::abs(b - y); };

    int n_floor = floor.size(), ans = 0;
    for (int i = 0; i < n_floor; i++) {
        for (int j = i + 1; j < n_floor; j++) {
            int curr = 0;
            for (int k = 0; k < h; k++) {
                for (int m = 0; m < w; m++) {
                    if (grid[k][m] == '.' && (F(k, m, floor[i].first, floor[i].second) <= d ||
                                              F(k, m, floor[j].first, floor[j].second) <= d)) {
                        ++curr;
                    }
                }
            }
            ans = std::max(ans, curr);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
