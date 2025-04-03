class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int ans = std::numeric_limits<int>::min();
        int curr_max = 1, curr_min = 1;
        for (auto elem : nums) {
            if (elem >= 0) {
                curr_max = std::max(curr_max * elem, elem);
                curr_min = std::min(curr_min * elem, elem);
            } else {
                std::tie(curr_max, curr_min) = std::make_tuple(std::max(curr_min * elem, elem),
                                                               std::min(curr_max * elem, elem));
            }
            ans = std::max(ans, curr_max);
        }
        return ans;
    }
};
