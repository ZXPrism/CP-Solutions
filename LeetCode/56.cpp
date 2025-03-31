class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        std::vector<std::vector<int>> ans;
        std::ranges::sort(intervals, [&](auto &lhs, auto &rhs) { return lhs[0] < rhs[0]; });
        int n = intervals.size();
        int i = 0;
        while (i < n) {
            int right = intervals[i][1];
            int j = i + 1;
            while (j < n && intervals[j][0] <= right) {
                right = std::max(right, intervals[j][1]);
                ++j;
            }
            ans.push_back({intervals[i][0], right});
            i = j;
        }
        return ans;
    }
};
