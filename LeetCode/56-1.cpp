class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals) {
		std::vector<std::vector<int>> ans;
		std::ranges::sort(intervals);
		int n = intervals.size();
		int left = 0;
		while (left < n) {
			int L = intervals[left][0], R = intervals[left][1];
			int right = left + 1;
			while (right < n && intervals[right][0] <= R) {
				R = std::max(R, intervals[right][1]);
				++right;
			}
			ans.push_back({ L, R });
			left = right;
		}
		return ans;
	}
};
