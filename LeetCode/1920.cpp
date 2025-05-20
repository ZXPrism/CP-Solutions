class Solution {
public:
	vector<int> buildArray(vector<int> &nums) {
		int n = nums.size();
		for (int i = 0; i < n; i++) {
			if (nums[i] >= 0) {
				int x = nums[i];
				int curr = i;
				while (nums[curr] != i) {
					int nxt = nums[curr];
					nums[curr] = ~nums[nxt];
					curr = nxt;
				}
				nums[curr] = ~x;
			}
		}
		for (auto &elem : nums) {
			elem = ~elem;
		}
		return nums;
	}
};
