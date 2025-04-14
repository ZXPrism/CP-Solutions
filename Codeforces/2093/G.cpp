#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::vector<std::array<int, 2>> trie;
    std::vector<int> cnt;

    auto NewNode = [&]() {
        auto &node = trie.emplace_back();
        node[0] = node[1] = -1;
        cnt.push_back(0);
    };
    NewNode();

    auto Insert = [&](int x) {
        int curr = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = x >> i & 1;
            if (trie[curr][bit] == -1) {
                trie[curr][bit] = trie.size();
                NewNode();
            }
            curr = trie[curr][bit];
            ++cnt[curr];
        }
    };

    auto Remove = [&](int x) {
        int curr = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = x >> i & 1;
            curr = trie[curr][bit];
            --cnt[curr];
        }
    };

    auto Get = [&](int x) -> int {
        int curr = 0, ans = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = x >> i & 1;
            if (trie[curr][!bit] == -1 || !cnt[trie[curr][!bit]]) {
                curr = trie[curr][bit];
            } else {
                curr = trie[curr][!bit];
                ans |= 1 << i;
            }
        }
        return ans;
    };

    int ans = n + 1;
    for (int left = 0, right = 0; right < n; right++) {
        Insert(v[right]);
        while (left <= right && Get(v[right]) >= k) {
            ans = std::min(ans, right - left + 1);
            Remove(v[left]);
            ++left;
        }
    }

    std::cout << (ans == n + 1 ? -1 : ans) << '\n';
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
