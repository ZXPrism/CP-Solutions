class Solution {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size(), ans = 0;
        heights.push_back(-1);
        std::stack<int> st;
        st.push(-1);
        for (int i = 0; i < n + 1; i++) {
            while (st.size() != 1 && heights[i] <= heights[st.top()]) {
                int top = st.top();
                st.pop();
                ans = std::max(ans, (i - st.top() - 1) * heights[top]);
            }
            st.push(i);
        }
        return ans;
    }
};
