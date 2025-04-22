class Solution {
public:
	int semiOrderedPermutation(vector<int> &nums) {
		int n = nums.size();
		int one_idx = -1, n_idx = -1;
		for (int i = 0; i < n; i++) {
			if (nums[i] == 1) {
				one_idx = i;
			} else if (nums[i] == n) {
				n_idx = i;
			}
		}
		return one_idx + n - 1 - n_idx - (one_idx > n_idx);
	}
};
