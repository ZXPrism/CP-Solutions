class Solution {
public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        int row = matrix.size(), col = matrix[0].size(), ans = 0;

        std::vector<int> height(col + 1);
        height[col] = -1;
        for (int i = 0; i < row; i++) {
            std::stack<int> st;
            st.push(-1);
            for (int j = 0; j <= col; j++) {
                if (j < col) {
                    height[j] = (matrix[i][j] == '1' ? 1 + height[j] : 0);
                }
                while (st.size() != 1 && height[j] <= height[st.top()]) {
                    int mid = st.top();
                    st.pop();
                    ans = std::max(ans, height[mid] * (j - st.top() - 1));
                }
                st.push(j);
            }
        }

        return ans;
    }
};
