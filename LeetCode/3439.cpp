class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime) {
        int n = startTime.size(), ans = 0, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += endTime[i] - startTime[i];
            if (i >= k - 1) {
                int right = (i + 1 == n ? eventTime : startTime[i + 1]);
                int left = (i == k - 1 ? 0 : endTime[i - k]);
                ans = std::max(ans, right - left - sum);
                sum -= endTime[i - k + 1] - startTime[i - k + 1];
            }
        }
        return ans;
    }
};
