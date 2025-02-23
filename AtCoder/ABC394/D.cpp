#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::map<char, char> match;
    match['('] = ')';
    match['['] = ']';
    match['<'] = '>';

    std::stack<char> st;
    for (auto ch : s) {
        if (match.contains(ch)) {
            st.push(ch);
        } else {
            if (st.empty() || match[st.top()] != ch) {
                std::cout << "No\n";
                return;
            }
            st.pop();
        }
    }

    if (st.empty()) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
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
