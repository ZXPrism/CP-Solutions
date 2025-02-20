class Solution {
public:
    int minAbsoluteSumDiff(vector<int> &nums1, vector<int> &nums2) {
        int n = nums1.size();

        std::vector<int> idx(n);
        std::iota(idx.begin(), idx.end(), 0);
        std::ranges::sort(idx, [&](int lhs, int rhs) { return nums1[lhs] < nums1[rhs]; });

        long long ans = 0, curr = 0;
        for (int i = 0; i < n; i++) {
            curr += std::abs(nums1[i] - nums2[i]);
        }
        ans = curr;

        for (int i = 0; i < n; i++) {
            int left = -1, right = n, mid = 0;
            while (left + 1 < right) {
                mid = (left + right) / 2;
                if (nums1[idx[mid]] >= nums2[idx[i]]) {
                    right = mid;
                } else {
                    left = mid;
                }
            }
            if (right != 0) {
                ans = std::min(ans, curr - std::abs(nums1[idx[i]] - nums2[idx[i]]) +
                                        std::abs(nums1[idx[right - 1]] - nums2[idx[i]]));
            }
            if (right != n) {
                ans = std::min(ans, curr - std::abs(nums1[idx[i]] - nums2[idx[i]]) +
                                        std::abs(nums1[idx[right]] - nums2[idx[i]]));
            }
        }

        return ans % 1'000'000'007;
    }
};
