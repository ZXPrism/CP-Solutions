class Solution {
public:
    int maxScore(vector<int> &cardPoints, int k) {
        int n = cardPoints.size(), len = n - k;
        int tot = std::accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if (len == 0) {
            return tot;
        }

        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sum += cardPoints[i];
            if (i >= len - 1) {
                ans = std::max(ans, tot - sum);
                sum -= cardPoints[i - len + 1];
            }
        }
        return ans;
    }
};
