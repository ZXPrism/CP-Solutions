#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int q = 0;
    std::cin >> q;

    i64 curr = 0, tot = 0, n = 0;
    int head = 0;
    std::list<int> lst;
    for (int i = 0; i < q; i++) {
        int s = 0;
        std::cin >> s;

        if (s == 1) {
            if (head == 0) {
                int val = lst.back();
                curr = curr + tot - n * val;
                lst.pop_back();
                lst.push_front(val);
            } else {
                int val = lst.front();
                curr = curr + tot - n * val;
                lst.pop_front();
                lst.push_back(val);
            }
        } else if (s == 2) {
            curr = (n + 1) * tot - curr;
            head ^= 1;
        } else {
            int k = 0;
            std::cin >> k;
            curr += (n + 1) * k;
            if (head == 0) {
                lst.push_back(k);
            } else {
                lst.push_front(k);
            }
            ++n;
            tot += k;
        }

        std::cout << curr << '\n';
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
