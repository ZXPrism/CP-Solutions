#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::queue<int> q;
    std::vector<int> indeg(n);
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n; i++) {
        int v = 0;
        while (std::cin >> v) {
            if (v == 0) {
                break;
            }
            --v;
            adj[i].push_back(v);
            ++indeg[v];
        }
    }

    std::vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (!indeg[i]) {
            q.push(i);
            ans.push_back(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto to : adj[u]) {
            if (--indeg[to] == 0) {
                q.push(to);
                ans.push_back(to);
            }
        }
    }

    for (auto elem : ans) {
        std::cout << elem + 1 << ' ';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
