class Solution {
public:
	int numberOfArrays(vector<int> &differences, int lower, int upper) {
		long long min_delta = 0, max_delta = 0, delta = 0;
		for (auto elem : differences) {
			delta += elem;
			min_delta = std::min(min_delta, delta);
			max_delta = std::max(max_delta, delta);
		}
		long long ub = std::min(1LL * upper, upper - max_delta);
		long long lb = std::max(1LL * lower, lower - min_delta);
		return std::max(0LL, ub - lb + 1);
	}
};
