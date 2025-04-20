class Solution {
public:
	vector<vector<int>> threeSum(vector<int> &nums) {
		std::vector<std::vector<int>> ans;
		std::ranges::sort(nums);
		int i = 0, n = nums.size();
		while (i < n) {
			int left = i + 1, right = n - 1, target = -nums[i];
			while (left < right) {
				int sum = nums[left] + nums[right];
				if (sum > target) {
					--right;
				} else if (sum < target) {
					++left;
				} else {
					ans.push_back({ nums[i], nums[left], nums[right] });
					if (nums[left] == nums[right]) {
						break;
					}
					int l = left, r = right;
					while (nums[left] == nums[l]) {
						++left;
					}
					while (nums[right] == nums[r]) {
						--right;
					}
				}
			}
			int j = i + 1;
			while (j < n && nums[j] == nums[i]) {
				++j;
			}
			i = j;
		}
		return ans;
	}
};
