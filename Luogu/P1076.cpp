#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> nums(n, std::vector<int>(m));
    std::vector<std::vector<int>> stair(n, std::vector<int>(m));
    std::vector<int> stair_cnt(n);
    int room = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> stair[i][j] >> nums[i][j];
            stair_cnt[i] += stair[i][j];
        }
    }
    std::cin >> room;

    int ans = 0;
    constexpr int MOD = 20123;
    for (int i = 0; i < n; i++) {
        ans = (ans + nums[i][room]) % MOD;
        int next = (nums[i][room] - 1) % stair_cnt[i];
        for (int j = 0; j < m; j++) {
            int curr_room = (room + j) % m;
            if (stair[i][curr_room]) {
                if (next-- == 0) {
                    room = curr_room;
                    break;
                }
            }
        }
    }

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
