class Solution {
public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = 0;
        std::ranges::sort(nums1);
        std::ranges::sort(nums2);

        for (int i = 0; i < n1; i++) {
            long long target = 1LL * nums1[i] * nums1[i];
            int left = 0, right = n2 - 1;
            while (left < right) {
                long long mul = 1LL * nums2[left] * nums2[right];
                if (mul == target) {
                    int a = left;
                    while (left <= right && nums2[left] == nums2[a]) {
                        ++left;
                    }
                    int b = right;
                    while (left <= right && nums2[right] == nums2[b]) {
                        --right;
                    }
                    if (left <= right || right != b) {
                        ans += (left - a) * (b - right);
                    } else {
                        ans += (b - a + 1) * (b - a) / 2;
                    }
                } else if (mul > target) {
                    --right;
                } else {
                    ++left;
                }
            }
        }

        for (int i = 0; i < n2; i++) {
            long long target = 1LL * nums2[i] * nums2[i];
            int left = 0, right = n1 - 1;
            while (left < right) {
                long long mul = 1LL * nums1[left] * nums1[right];
                if (mul == target) {
                    int a = left;
                    while (left <= right && nums1[left] == nums1[a]) {
                        ++left;
                    }
                    int b = right;
                    while (left <= right && nums1[right] == nums1[b]) {
                        --right;
                    }
                    if (left <= right || right != b) {
                        ans += (left - a) * (b - right);
                    } else {
                        ans += (b - a + 1) * (b - a) / 2;
                    }
                } else if (mul > target) {
                    --right;
                } else {
                    ++left;
                }
            }
        }

        return ans;
    }
};
