class Solution {
public:
	int numSubmat(vector<vector<int>> &mat) {
		int m = mat.size(), n = mat[0].size(), ans = 0;
		std::vector<int> heights(n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				heights[j] = (mat[i][j] ? heights[j] + 1 : 0);
			}
			for (int j = 0; j < n; j++) {
				int min_height = heights[j];
				for (int k = j; k >= 0; k--) {
					min_height = std::min(min_height, heights[k]);
					ans += min_height;
				}
			}
		}
		return ans;
	}
};
