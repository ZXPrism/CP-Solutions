class Solution {
public:
	template<typename T, typename Comparator = std::less<T>>
	class LazyHeap {
	private:
		std::priority_queue<int, std::vector<T>, Comparator> _Heap;
		std::unordered_map<T, int> _DelCnt;
		size_t _Size;

	public:
		T top() {
			_Maintain();
			return _Heap.top();
		}

		void push(const T &val) {
			if (_DelCnt[val]) {
				--_DelCnt[val];
			} else {
				_Heap.push(val);
			}
			++_Size;
		}

		void pop() {
			_Maintain();
			_Heap.pop();
			--_Size;
		}

		void remove(const T &val) {
			++_DelCnt[val];
			--_Size;
		}

		size_t size() const { return _Size; }

	private:
		void _Maintain() {
			while (!_Heap.empty() && _DelCnt[_Heap.top()]) {
				--_DelCnt[_Heap.top()];
				_Heap.pop();
			}
		}
	};

	vector<double> medianSlidingWindow(vector<int> &nums, int k) {
		int n = nums.size();
		std::vector<double> ans(n - k + 1);
		LazyHeap<int> left;
		LazyHeap<int, std::greater<>> right;
		for (int i = 0; i < n; i++) {
			if (left.size() == right.size()) {
				left.push(nums[i]);
				right.push(left.top());
				left.pop();
			} else {
				right.push(nums[i]);
				left.push(right.top());
				right.pop();
			}
			if (i - k + 1 >= 0) {
				if (k & 1) {
					ans[i - k + 1] = right.top();
					if (nums[i - k + 1] >= right.top()) {
						right.remove(nums[i - k + 1]);
					} else {
						left.remove(nums[i - k + 1]);
						left.push(right.top());
						right.pop();
					}
				} else {
					ans[i - k + 1] = (1LL * left.top() + right.top()) / 2.0;
					if (nums[i - k + 1] >= right.top()) {
						right.remove(nums[i - k + 1]);
						right.push(left.top());
						left.pop();
					} else {
						left.remove(nums[i - k + 1]);
					}
				}
			}
		}
		return ans;
	}
};
