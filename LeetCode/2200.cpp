class Solution {
public:
	vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
		int n = nums.size();
		std::vector<int> pre(n + 1);
		for (int i = 0; i < n; i++) {
			pre[i + 1] = pre[i];
			if (nums[i] == key) {
				++pre[i + 1];
			}
		}

		std::vector<int> ans;
		for (int i = 0; i < n; i++) {
			if (pre[std::min(n - 1, i + k) + 1] - pre[std::max(0, i - k)]) {
				ans.push_back(i);
			}
		}

		return ans;
	}
};
