class Solution {
public:
    int maximumScore(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0;
        nums.push_back(-1);
        std::stack<int> st;
        st.push(-1);
        for (int i = 0; i < n + 1; i++) {
            while (st.size() != 1 && nums[i] <= nums[st.top()]) {
                int mid = st.top();
                st.pop();
                if (st.top() < k && i > k) {
                    ans = std::max(ans, nums[mid] * (i - st.top() - 1));
                }
            }
            st.push(i);
        }
        return ans;
    }
};
