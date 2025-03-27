class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &nums) {
        int n = nums.size();
        std::vector<int> ans(n, -1);
        std::stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i % n] >= st.top()) {
                st.pop();
            }
            if (i < n && !st.empty()) {
                ans[i] = st.top();
            }
            st.push(nums[i % n]);
        }
        return ans;
    }
};
