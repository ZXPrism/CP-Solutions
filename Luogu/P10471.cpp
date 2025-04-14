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

    std::vector<std::array<int, 2>> trie;
    std::vector<int> cnt;

    auto NewNode = [&]() {
        trie.emplace_back();
        cnt.emplace_back();
        trie.back()[0] = trie.back()[1] = -1;
    };
    NewNode();

    for (int i = 0; i < n; i++) {
        int curr = 0;
        for (int j = 30; j >= 0; j--) {
            if (trie[curr][v[i] >> j & 1] == -1) {
                trie[curr][v[i] >> j & 1] = trie.size();
                NewNode();
            }
            curr = trie[curr][v[i] >> j & 1];
            ++cnt[curr];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int curr = 0, final = 0;
        for (int j = 30; j >= 0; j--) {
            int bit = v[i] >> j & 1;
            if (trie[curr][!bit] != -1) {
                curr = trie[curr][!bit];
                final |= !bit << j;
            } else {
                curr = trie[curr][bit];
                final |= bit << j;
            }
        }
        ans = std::max(ans, v[i] ^ final);
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
