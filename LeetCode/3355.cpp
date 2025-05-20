class Solution {
public:
	bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
		int n = nums.size();
		std::vector<int> diff(n + 1);
		for (auto &qry : queries) {
			++diff[qry[0]];
			--diff[qry[1] + 1];
		}
		for (int x = 0, i = 0; i < n; i++) {
			x += diff[i];
			if (x < nums[i]) {
				return false;
			}
		}
		return true;
	}
};
