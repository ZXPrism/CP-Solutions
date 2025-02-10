#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> face(n);
    std::vector<std::map<int, int>> dices(n);
    for (int i = 0; i < n; i++) {
        std::cin >> face[i];

        for (int j = 0; j < face[i]; j++) {
            int t = 0;
            std::cin >> t;
            ++dices[i][t];
        }
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double curr = 0;
            for (auto [val, cnt] : dices[i]) {
                if (dices[j].contains(val)) {
                    curr += 1.0 * cnt * dices[j][val] / (1LL * face[i] * face[j]); // LL...WA x3
                }
            }
            ans = std::max(ans, curr);
        }
    }

    std::cout.setf(std::ios::fixed);
    std::cout << std::setprecision(9) << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
