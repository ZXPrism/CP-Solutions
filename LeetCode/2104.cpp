class Solution {
public:
    long long subArrayRanges(vector<int> &nums) {
        long long ans = 0;
        int n = nums.size();

        std::stack<int> min_st;
        nums.push_back(-1'000'000'001);
        min_st.push(-1);
        for (int i = 0; i <= n; i++) {
            while (min_st.size() != 1 && nums[i] <= nums[min_st.top()]) {
                int mid = min_st.top();
                min_st.pop();
                ans -= 1LL * nums[mid] * (mid - min_st.top()) * (i - mid);
            }
            min_st.push(i);
        }

        std::stack<int> max_st;
        nums.back() = 1'000'000'001;
        max_st.push(-1);
        for (int i = 0; i <= n; i++) {
            while (max_st.size() != 1 && nums[i] >= nums[max_st.top()]) {
                int mid = max_st.top();
                max_st.pop();
                ans += 1LL * nums[mid] * (mid - max_st.top()) * (i - mid);
            }
            max_st.push(i);
        }

        return ans;
    }
};
