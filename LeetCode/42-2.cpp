class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size(), ans = 0;
        std::stack<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int curr = height[st.top()];
                st.pop();
                if (!st.empty()) {
                    ans += (std::min(height[st.top()], height[i]) - curr) * (i - st.top() - 1);
                }
            }
            st.push(i);
        }
        return ans;
    }
};
