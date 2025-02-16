#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> tests(m);
    std::vector<int> results(m);

    for (int i = 0; i < m; i++) {
        int cnt = 0;
        std::cin >> cnt;

        for (int j = 0; j < cnt; j++) {
            int t = 0;
            std::cin >> t;
            --t;
            tests[i].push_back(t);
        }

        char res = 0;
        std::cin >> res;
        results[i] = (res == 'o' ? 1 : 0);
    }

    int ans = 0;
    for (int i = 0; i < (1 << n); i++) {
        bool flag = true;
        for (int j = 0; j < m; j++) {
            int check = 0;
            for (auto elem : tests[j]) {
                check += (i >> elem & 1);
            }
            if ((check >= k) ^ results[j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            ++ans;
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
