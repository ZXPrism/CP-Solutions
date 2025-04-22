class Solution {
public:
	int findKthLargest(vector<int> &nums, int k) {
		int n = nums.size();
		std::random_device rd;
		std::mt19937_64 engine(rd());
		auto partition = [&](int left, int right) -> std::pair<int, int> {
			std::uniform_int_distribution<int> dist(left, right);
			int pivot = nums[dist(engine)];
			int i = left, j = left, k = right + 1;
			while (i < k) {
				if (nums[i] > pivot) {
					std::swap(nums[i], nums[j]);
					++i;
					++j;
				} else if (nums[i] == pivot) {
					++i;
				} else {
					--k;
					std::swap(nums[i], nums[k]);
				}
			}
			return { j, k };
		};

		int left = 0, right = n - 1;
		while (1) {
			auto [L, R] = partition(left, right);
			if (k - 1 < L) {
				right = L - 1;
			} else if (k - 1 >= R) {
				left = R;
			} else {
				return nums[L];
			}
		}

		return 114514;
	}
};
