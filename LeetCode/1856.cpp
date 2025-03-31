class Solution {
public:
    int maxSumMinProduct(vector<int> &nums) {
        using i64 = long long;
        i64 ans = 0;
        int n = nums.size();
        std::vector<i64> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + nums[i];
        }
        std::stack<int> st;
        st.push(-1);
        nums.push_back(-1);
        for (int i = 0; i <= n; i++) {
            while (st.size() != 1 && nums[i] <= nums[st.top()]) {
                int mid = st.top();
                st.pop();
                ans = std::max(ans, nums[mid] * (pre[i] - pre[st.top() + 1]));
            }
            st.push(i);
        }
        return ans % 1'000'000'007;
    }
};
