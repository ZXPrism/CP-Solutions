class Solution {
public:
	int numSubmat(vector<vector<int>> &mat) {
		int m = mat.size(), n = mat[0].size(), ans = 0;
		std::vector<int> heights(n + 1);
		heights[n] = -1;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				heights[j] = (mat[i][j] ? heights[j] + 1 : 0);
			}
			std::stack<int> st;
			st.push(-1);
			for (int j = 0; j <= n; j++) {
				while (st.size() != 1 && heights[j] <= heights[st.top()]) {
					auto mid = st.top();
					st.pop();
					ans += heights[mid] * (j - mid) * (mid - st.top());
				}
				st.push(j);
			}
		}
		return ans;
	}
};
