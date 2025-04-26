class Solution {
public:
	int search(vector<int> &nums, int target) {
		int n = nums.size();
		if (n == 1) {
			return target == nums[0] ? 0 : -1;
		}
		int left = -1, right = n, mid = 0;
		while (left + 1 < right) {
			mid = (left + right) >> 1;
			if (nums[mid] >= nums[0]) {
				if (target >= nums[0]) {
					if (target >= nums[mid]) {
						left = mid;
					} else {
						right = mid;
					}
				} else {
					left = mid;
				}
			} else {
				if (target >= nums[0]) {
					right = mid;
				} else {
					if (target >= nums[mid]) {
						left = mid;
					} else {
						right = mid;
					}
				}
			}
		}
		return left >= 0 && left < n && nums[left] == target ? left : -1;
	}
};
