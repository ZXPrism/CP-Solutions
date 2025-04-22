class Solution {
public:
	void sortColors(vector<int> &nums) {
		int n = nums.size();
		int i = 0, j = 0, k = n;
		while (i < k) {
			if (nums[i] == 0) {
				std::swap(nums[i], nums[j]);
				++i;
				++j;
			} else if (nums[i] == 1) {
				++i;
			} else {
				--k;
				std::swap(nums[i], nums[k]);
			}
		}
	}
};
