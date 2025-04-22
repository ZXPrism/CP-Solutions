class Solution {
public:
	int findKthLargest(vector<int> &nums, int k) {
		std::priority_queue<int, std::vector<int>, std::greater<>> heap;
		for (auto elem : nums) {
			heap.push(elem);
			if (heap.size() > k) {
				heap.pop();
			}
		}
		return heap.top();
	}
};
