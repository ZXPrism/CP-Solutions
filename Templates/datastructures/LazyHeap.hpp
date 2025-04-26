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
