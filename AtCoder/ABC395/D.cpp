#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, q = 0;
    std::cin >> n >> q;

    std::vector<int> pigeon2id(n + 1), id2nest(n + 1), nest2id(n + 1);
    for (int i = 1; i <= n; i++) {
        pigeon2id[i] = i;
        id2nest[i] = i;
        nest2id[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int op = 0, a = 0, b = 0;
        std::cin >> op;
        if (op == 1) { // move
            std::cin >> a >> b;
            pigeon2id[a] = nest2id[b];
        } else if (op == 2) { // swap
            std::cin >> a >> b;
            int id_a = nest2id[a], id_b = nest2id[b];
            std::swap(id2nest[id_a], id2nest[id_b]);
            std::swap(nest2id[a], nest2id[b]);
        } else { // report
            std::cin >> a;
            std::cout << id2nest[pigeon2id[a]] << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
