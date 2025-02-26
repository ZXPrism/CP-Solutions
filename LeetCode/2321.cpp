class Solution {
public:
    int maximumsSplicedArray(vector<int> &nums1, vector<int> &nums2) {
        int s1 = std::reduce(nums1.begin(), nums1.end());
        int s2 = std::reduce(nums2.begin(), nums2.end());
        int ans = std::max(s1, s2);

        int n = nums1.size(), INF = std::numeric_limits<int>::max();
        int curr_min = 0, curr_max = 0, mx = -INF, mi = INF;
        for (int i = 0; i < n; i++) {
            int curr = -nums1[i] + nums2[i];
            curr_min = std::min(curr_min + curr, curr);
            curr_max = std::max(curr_max + curr, curr);
            mi = std::min(mi, curr_min);
            mx = std::max(mx, curr_max);
        }
        ans = std::max({s1 + mx, s2 - mx, s1 + mi, s2 - mi});

        return ans;
    }
};
