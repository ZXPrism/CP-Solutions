class Solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        int n = customers.size(), ans = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += customers[i] * (1 - grumpy[i]);
        }

        int extra = 0;
        for (int i = 0; i < n; i++) {
            extra += grumpy[i] * customers[i];
            if (i >= minutes - 1) {
                ans = std::max(ans, total + extra);
                extra -= grumpy[i - minutes + 1] * customers[i - minutes + 1];
            }
        }

        return ans;
    }
};
