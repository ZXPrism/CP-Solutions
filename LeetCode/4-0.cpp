class Solution {
public:
	double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
		int m = nums1.size(), n = nums2.size();
		int len = (m + n) >> 1;
		for (int i = 0; i <= m; i++) {
			int other = len - i;
			if (other >= 0 && other <= n) {
				int left_max = -0x3f3f3f3f, right_min = 0x3f3f3f3f;
				if (i) {
					left_max = std::max(left_max, nums1[i - 1]);
				}
				if (other) {
					left_max = std::max(left_max, nums2[other - 1]);
				}
				if (i != m) {
					right_min = std::min(right_min, nums1[i]);
				}
				if (other != n) {
					right_min = std::min(right_min, nums2[other]);
				}
				if (left_max <= right_min) {
					return ((m + n) & 1 ? right_min
					                    : (left_max + right_min) / 2.0);
				}
			}
		}
		return -1;
	}
};
