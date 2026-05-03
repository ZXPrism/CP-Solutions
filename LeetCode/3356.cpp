class Solution {
public:
	int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
		int n = nums.size(), q = queries.size();
		auto check = [&](int k) -> bool {
			std::vector<int> diff(n + 1);
			for (int i = 0; i < k; i++) {
				diff[queries[i][0]] += queries[i][2];
				diff[queries[i][1] + 1] -= queries[i][2];
			}
			for (int x = 0, i = 0; i < n; i++) {
				x += diff[i];
				if (nums[i] > x) {
					return false;
				}
			}
			return true;
		};
		int left = -1, right = q + 1, mid = 0;
		while (left + 1 < right) {
			mid = (left + right) >> 1;
			if (check(mid)) {
				right = mid;
			} else {
				left = mid;
			}
		}
		return (right == q + 1 ? -1 : right);
	}
};
