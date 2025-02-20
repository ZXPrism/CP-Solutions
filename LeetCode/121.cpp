class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ans = 0, curr_min = 10001;
        for (auto elem : prices) {
            ans = std::max(ans, elem - curr_min);
            curr_min = std::min(curr_min, elem);
        }
        return ans;
    }
};
