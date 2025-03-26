class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        constexpr int MOD = 1'000'000'007;
        int n = arr.size(), ans = 0;

        std::stack<int> st;
        st.push(-1);

        std::vector<int> dp_sum(n + 1);
        for (int i = 0; i < n; i++) {
            while (st.size() > 1 && arr[i] <= arr[st.top()]) {
                st.pop();
            }
            dp_sum[i + 1] = dp_sum[st.top() + 1] + (i - st.top()) * arr[i];
            ans = (ans + dp_sum[i + 1]) % MOD;
            st.push(i);
        }

        return ans;
    }
};
