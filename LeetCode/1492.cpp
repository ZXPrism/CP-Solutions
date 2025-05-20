class Solution {
public:
	int kthFactor(int n, int k) {
		std::vector<int> fac;
		int sqrt_n = std::sqrt(n), cnt = 0;
		for (int i = 1; i <= sqrt_n; i++) {
			if (n % i == 0) {
				fac.push_back(i);
				fac.push_back(n / i);
			}
		}
		if (sqrt_n * sqrt_n == n) {
			fac.pop_back();
		}
		std::ranges::sort(fac);
		return k <= fac.size() ? fac[k - 1] : -1;
	}
};
