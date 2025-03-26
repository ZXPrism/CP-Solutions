class Solution {
public:
    vector<int> finalPrices(vector<int> &prices) {
        int n = prices.size();
        std::stack<int> s;
        std::vector<int> ans = prices;
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && prices[i] < prices[s.top()]) {
                s.pop();
            }
            if (!s.empty()) {
                ans[i] -= prices[s.top()];
            }
            s.push(i);
        }
        return ans;
    }
};
