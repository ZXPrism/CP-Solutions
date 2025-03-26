class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        std::vector<int> pos(10001);
        std::stack<int> s;
        std::vector<int> next(n2, -1);
        for (int i = 0; i < n2; i++) {
            pos[nums2[i]] = i;
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                next[s.top()] = i;
                s.pop();
            }
            s.push(i);
        }
        std::vector<int> ans(n1, -1);
        for (int i = 0; i < n1; i++) {
            if (next[pos[nums1[i]]] != -1) {
                ans[i] = nums2[next[pos[nums1[i]]]];
            }
        }
        return ans;
    }
};
