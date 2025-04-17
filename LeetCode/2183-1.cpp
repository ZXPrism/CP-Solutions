class Solution {
public:
	long long countPairs(vector<int> &nums, int k) {
		int sqrt_k = static_cast<int>(std::sqrt(k));
		std::vector<int> k_divisors;
		for (int i = 1; i <= sqrt_k; i++) {
			k_divisors.push_back(i);
			if (i * i != k) {
				k_divisors.push_back(k / i);
			}
		}
		long long ans = 0;
		std::unordered_map<int, int> cnt;
		for (auto elem : nums) {
			int target = k / std::gcd(k, elem);
			ans += cnt[target];
			for (auto d : k_divisors) {
				if (elem % d == 0) {
					++cnt[d];
				}
			}
		}
		return ans;
	}
};
