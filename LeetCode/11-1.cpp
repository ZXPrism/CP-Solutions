class Solution {
public:
    int maxArea(vector<int> &height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while (left < right) {
            if (height[left] <= height[right]) {
                ans = std::max(ans, height[left] * (right - left));
                ++left;
            } else {
                ans = std::max(ans, height[right] * (right - left));
                --right;
            }
        }
        return ans;
    }
};
