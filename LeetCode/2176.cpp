constexpr int INF = 0x3f3f3f3f;
constexpr int V = 100;
constexpr int MAXN = 100;

std::vector<int> divisors[MAXN + 1];

auto prep = []() {
	for (int i = 1; i <= MAXN; i++) {
		for (int j = i; j <= MAXN; j += i) {
			divisors[j].push_back(i);
		}
	}
	return 0;
}();

class Solution {
public:
	int countPairs(vector<int> &nums, int k) {
		int n = nums.size();
		std::vector<int> nxt(n);
		std::vector<int> pos(V + 1, INF);
		for (int i = n - 1; i >= 0; i--) {
			nxt[i] = pos[nums[i]];
			pos[nums[i]] = i;
		}
		int ans = 0;
		for (int i = 1; i <= V; i++) {
			std::vector<int> cnt(V + 1);
			int j = pos[i];
			while (j != INF) {
				if (j) {
					int target = k / std::gcd(k, j);
					if (target <= V) {
						ans += cnt[target];
					}
					ans += cnt[0];
					for (auto elem : divisors[j]) {
						++cnt[elem];
					}
				} else {
					++cnt[0];
				}

				j = nxt[j];
			}
		}
		return ans;
	}
};
