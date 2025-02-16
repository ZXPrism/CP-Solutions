class Solution {
public:
    int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper) {
        int ans = 0;
        int sum = 0, n = calories.size();
        for (int i = 0; i < n; i++) {
            sum += calories[i];
            if (i >= k - 1) {
                if (sum > upper) {
                    ++ans;
                } else if (sum < lower) {
                    --ans;
                }
                sum -= calories[i - k + 1];
            }
        }
        return ans;
    }
};
