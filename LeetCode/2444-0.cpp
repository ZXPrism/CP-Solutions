class Solution {
public:
	long long countSubarrays(vector<int> &nums, int minK, int maxK) {
		int max_elem = *std::ranges::max_element(nums);
		max_elem = std::max({ max_elem, minK, maxK });

		int n = nums.size();

		std::vector<int> next_le(n, n), next_ge(n, n);
		std::vector<int> prev_l(n, -1), prev_g(n, -1);

		std::stack<int> st_l, st_g;
		for (int i = 0; i < n; i++) {
			while (!st_l.empty() && nums[i] <= nums[st_l.top()]) {
				next_le[st_l.top()] = i;
				st_l.pop();
			}
			if (!st_l.empty()) {
				prev_l[i] = st_l.top();
			}
			st_l.push(i);

			while (!st_g.empty() && nums[i] >= nums[st_g.top()]) {
				next_ge[st_g.top()] = i;
				st_g.pop();
			}
			if (!st_g.empty()) {
				prev_g[i] = st_g.top();
			}
			st_g.push(i);
		}

		long long ans = 0;
		std::vector<int> last(max_elem + 1, -1);
		for (int i = 0; i < n; i++) {
			last[nums[i]] = i;
			int start = std::min(last[minK], last[maxK]);
			if (start != -1 && next_le[last[minK]] > i &&
			    next_ge[last[maxK]] > i) {
				int end = std::max(prev_l[last[minK]], prev_g[last[maxK]]);
				if (end < start) {
					ans += start - end;
				}
			}
		}

		return ans;
	}
};
