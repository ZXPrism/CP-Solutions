class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int cand = 0, cnt = 0;
        for (auto elem : nums) {
            if (!cnt) {
                cand = elem;
            }
            if (elem == cand) {
                ++cnt;
            } else {
                --cnt;
            }
        }
        return cand;
    }
};
