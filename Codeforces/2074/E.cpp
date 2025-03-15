#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

std::mt19937_64 engine;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> initial(n);
    std::iota(initial.begin(), initial.end(), 1);
    std::shuffle(initial.begin(), initial.end(), engine);

    std::uniform_int_distribution<int> dist(0, 2);

    auto query = [](int params[3]) -> int {
        std::cout << std::format("? {} {} {}", params[0], params[1], params[2]) << std::endl;
        int ans = 0;
        std::cin >> ans;
        return ans;
    };

    auto answer = [](int params[3]) -> void {
        std::cout << std::format("! {} {} {}", params[0], params[1], params[2]) << std::endl;
    };

    int params[] = {initial[0], initial[1], initial[2]};
    while (1) {
        int ans = query(params);

        if (ans < 0) {
            std::exit(0);
        } else if (ans == 0) {
            answer(params);
            break;
        }

        params[dist(engine)] = ans;
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::random_device rd;
    engine.seed(rd());

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
