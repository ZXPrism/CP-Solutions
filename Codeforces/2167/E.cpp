#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	// 只有 1 个人，优先在更远的地方摆放传送门
	// 对于给定摆放方案，可以得到每个人需要行走的距离，我们找出最短距离 s
	// 目标即为求最短距离 s 取得最大值时的摆放方案
	// KEY 1: 给定任意最短距离 s，能否构造出摆放方案？
	// KEY 2：给定摆放方案，如何快速求得最短距离？O(nlogn)？
	// 如果某个摆放方案是合法的，那么对于更小的最短距离，它依然合法
	// 如果对于某个最短距离，不存在任何合法摆放方案，那么对于更大的最短距离，也不存在这样的方案，否则就矛盾了
	// 或许可以二分？

	// 对于某个传送门，如果某个人对它来说是最近的，并不代表那个人最近的传送门是它；它和那个人的距离一定大于等于那个人和最近传送门的距离
	// 因此，在合法的摆放方案里，每个传送门和最近的人的距离一定大于等于那个人和最近传送门的距离，也大于等于最短距离 s
	// 如果每个传送门和最近的人的距离都大于等于 s‘，是否能说明该方案是合法的？是。反证法可证。
	// 事实上，这是等价条件。

	// 开始构造方案
	int n = 0;
	int k = 0;
	int x = 0;
	std::cin >> n >> k >> x;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}
	std::sort(v.begin(), v.end());  // TRAP...不一定预排序，如果样例不全就 WA2 了。。

	auto check = [&](int min_dist) -> bool {
		int cnt = std::max(0, v[0] - min_dist + 1) + std::max(0, x + 1 - (v.back() + min_dist));
		for (int i = 1; i < n; i++) {
			int left = v[i - 1] + min_dist;
			int right = v[i] - min_dist;
			cnt += std::max(0, right - left + 1);
		}
		return cnt >= k;
	};

	int left = -1;
	int right = x + 1;
	int mid = 0;
	while (left + 1 < right) {
		mid = (left + right) >> 1;
		if (check(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}

	if (left == 0) {
		for (int i = 0; i < k; i++) {
			std::cout << i << " \n"[i == k - 1];
		}
		return;
	}

	std::vector<int> ans;
	auto print_ans = [&]() {
		for (int i = 0; i < k; i++) {
			std::cout << ans[i] << " \n"[i == k - 1];
		}
	};

	for (int i = 0; i <= v[0] - left; i++) {
		ans.push_back(i);
		if (ans.size() == k) {
			print_ans();
			return;
		}
	}

	for (int i = v.back() + left; i <= x; i++) {
		ans.push_back(i);
		if (ans.size() == k) {
			print_ans();
			return;
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = v[i - 1] + left; j <= v[i] - left; j++) {
			ans.push_back(j);
			if (ans.size() == k) {
				print_ans();
				return;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	preprocess();

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
