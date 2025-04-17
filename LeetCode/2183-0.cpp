constexpr int V = 1'0000'0;

std::vector<int> divisors[V + 1];

auto prep = []() {
	for (int i = 1; i <= V; i++) {
		for (int j = i; j <= V; j += i) {
			divisors[j].push_back(i);
		}
	}
	return 0;
}();

class Solution {
public:
	long long countPairs(vector<int> &nums, int k) {
		long long ans = 0;
		std::unordered_map<int, int> cnt;
		for (auto elem : nums) {
			int target = k / std::gcd(k, elem);
			ans += cnt[target];
			for (auto d : divisors[elem]) {
				++cnt[d];
			}
		}
		return ans;
	}
};
