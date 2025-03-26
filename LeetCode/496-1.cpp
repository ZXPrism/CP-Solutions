class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        std::vector<int> pos(10001);
        std::stack<int> s;
        std::vector<int> next(n2, -1);
        for (int i = n2 - 1; i >= 0; i--) {
            pos[nums2[i]] = i;
            while (!s.empty() && nums2[i] > s.top()) {
                s.pop();
            }
            if (!s.empty()) {
                next[i] = s.top();
            }
            s.push(nums2[i]);
        }
        std::vector<int> ans(n1, -1);
        for (int i = 0; i < n1; i++) {
            if (next[pos[nums1[i]]] != -1) {
                ans[i] = next[pos[nums1[i]]];
            }
        }
        return ans;
    }
};
