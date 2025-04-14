#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

struct TrieNode {
    int cnt;
    std::array<int, 62> next;
};

void solve() {
    std::vector<TrieNode> trie;
    TrieNode $;
    $.cnt = 0;
    std::fill($.next.begin(), $.next.end(), -1);
    trie.push_back($);

    auto ID = [](char ch) -> int {
        if (ch <= '9') {
            return 52 + ch - '0';
        }
        return (ch & 31) + 26 * !!(ch & 32) - 1;
    };

    auto Insert = [&](const std::string &s) {
        int curr = 0;
        for (auto ch : s) {
            int id = ID(ch);
            if (trie[curr].next[id] == -1) {
                trie[curr].next[id] = trie.size();
                trie.push_back($);
            }
            curr = trie[curr].next[id];
            ++trie[curr].cnt;
        }
    };

    auto Get = [&](const std::string &s) {
        int curr = 0;
        for (auto ch : s) {
            int id = ID(ch);
            if (trie[curr].next[id] == -1) {
                return 0;
            }
            curr = trie[curr].next[id];
        }
        return trie[curr].cnt;
    };

    int n = 0, q = 0;
    std::cin >> n >> q;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        Insert(s);
    }

    for (int i = 0; i < q; i++) {
        std::string s;
        std::cin >> s;
        std::cout << Get(s) << '\n';
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
