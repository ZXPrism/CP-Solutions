template<typename T, typename Comparator = std::less<T>>
class DeleteableHeap {
private:
	std::priority_queue<int, std::vector<T>, Comparator> _Heap;
	std::priority_queue<int, std::vector<T>, Comparator> _DelHeap;
	size_t _Size;

public:
	T top() {
		_Maintain();
		return _Heap.top();
	}

	void push(const T &val) {
		_Heap.push(val);
		++_Size;
	}

	void pop() {
		_Maintain();
		_Heap.pop();
		--_Size;
	}

	void remove(const T &val) {
		_DelHeap.push(val);
		--_Size;
	}

	size_t size() const { return _Size; }

private:
	void _Maintain() {
		while (!_DelHeap.empty() && _Heap.top() == _DelHeap.top()) {
			_Heap.pop();
			_DelHeap.pop();
		}
	}
};
