class Solution {
public:
    int trap(vector<int> &height) {
        int left = 0, right = height.size() - 1;
        int pmax = 0, smax = 0, ans = 0;
        while (left <= right) {
            pmax = std::max(pmax, height[left]);
            smax = std::max(smax, height[right]);
            if (pmax <= smax) {
                ans += pmax - height[left];
                ++left;
            } else {
                ans += smax - height[right];
                --right;
            }
        }
        return ans;
    }
};
