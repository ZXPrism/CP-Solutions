#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<std::pair<int, int>>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u = 0, v = 0, w = 0;
        std::cin >> u >> v >> w;
        --u, --v;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    std::vector<std::array<int, 2>> trie;
    trie.emplace_back();
    trie[0][0] = trie[0][1] = -1;

    std::vector<int> vals(1, 0);
    int curr_weight = 0;
    auto dfs = [&](auto &&self, int node, int fa) -> void {
        for (auto [neighbor, weight] : adj[node]) {
            if (neighbor != fa) {
                curr_weight ^= weight;
                vals.push_back(curr_weight);
                self(self, neighbor, node);
                curr_weight ^= weight;
            }
        }
    };
    dfs(dfs, 0, -1);

    for (auto elem : vals) {
        int curr = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = elem >> i & 1;
            if (trie[curr][bit] == -1) {
                trie[curr][bit] = trie.size();
                trie.emplace_back();
                trie.back()[0] = trie.back()[1] = -1;
            }
            curr = trie[curr][bit];
        }
    }

    int ans = 0;
    for (auto elem : vals) {
        int curr = 0, cand = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = elem >> i & 1;
            if (trie[curr][!bit] != -1) {
                curr = trie[curr][!bit];
                cand |= !bit << i;
            } else {
                curr = trie[curr][bit];
                cand |= bit << i;
            }
        }
        ans = std::max(ans, elem ^ cand);
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
