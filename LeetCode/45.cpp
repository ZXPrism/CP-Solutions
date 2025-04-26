class Solution {
public:
	int jump(vector<int> &nums) {
		int n = nums.size(), curr_max = 0, tot_max = 0, ans = 0;
		for (int i = 0; i < n; i++) {
			if (i > curr_max) {
				curr_max = tot_max;
				++ans;
			}
			tot_max = std::max(tot_max, i + nums[i]);
		}
		return ans;
	}
};
