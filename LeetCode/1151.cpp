class Solution {
public:
    int minSwaps(vector<int> &data) {
        int n = data.size();
        int one = std::accumulate(data.begin(), data.end(), 0);
        if (one == 0) {
            return 0;
        }
        int ans = one, sum = 0;
        for (int i = 0; i < n; i++) {
            sum += 1 - data[i];
            if (i >= one - 1) {
                ans = std::min(ans, sum);
                sum -= 1 - data[i - one + 1];
            }
        }
        return ans;
    }
};
