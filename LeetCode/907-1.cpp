class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        constexpr int MOD = 1'000'000'007;

        std::stack<int> s;
        s.push(-1);

        int n = arr.size(), ans = 0;
        arr.push_back(-1);

        for (int right = 0; right < n + 1; right++) {
            while (s.size() > 1 && arr[right] <= arr[s.top()]) {
                int mid = s.top();
                s.pop();
                int L = mid - s.top();
                int R = right - mid;
                ans = (ans + 1LL * L * R * arr[mid]) % MOD;
            }
            s.push(right);
        }

        return ans;
    }
};
