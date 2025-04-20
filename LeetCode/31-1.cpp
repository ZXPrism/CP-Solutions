class Solution {
public:
	void nextPermutation(vector<int> &nums) {
		int n = nums.size();
		int left = n - 2;
		while (left >= 0 && nums[left] >= nums[left + 1]) {
			--left;
		}
		if (left >= 0) {
			int L = left, R = n, M = 0;
			while (L + 1 < R) {
				M = (L + R) >> 1;
				if (nums[M] > nums[left]) {
					L = M;
				} else {
					R = M;
				}
			}
			std::swap(nums[L], nums[left]);
		}
		std::reverse(nums.begin() + left + 1, nums.end());
	}
};
