class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int ans = std::numeric_limits<int>::min();
        int curr_min = 1, curr_max = 1;
        for (auto elem : nums) {
            if (elem >= 0) {
                std::tie(curr_min, curr_max) = std::make_tuple(std::min(curr_min * elem, elem),
                                                               std::max(curr_max * elem, elem));
            } else {
                std::tie(curr_min, curr_max) = std::make_tuple(std::min(curr_max * elem, elem),
                                                               std::max(curr_min * elem, elem));
            }
            ans = std::max(ans, curr_max);
        }
        return ans;
    }
};
