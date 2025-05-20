template<typename T>
struct Node {
	Node() = default;
	explicit Node(T data)
	    : _Data(data) {}
	T _Data;
	Node *_Prev = nullptr;
	Node *_Next = nullptr;
};

template<typename T>
class LinkedList {
private:
	Node<T> _Dummy;

	void _PushBackNode(Node<T> *node) {
		auto tail = _Dummy._Prev;
		tail->_Next = node;
		node->_Prev = tail;
		node->_Next = &_Dummy;
		_Dummy._Prev = node;
	}

public:
	LinkedList() {
		_Dummy._Next = &_Dummy;
		_Dummy._Prev = &_Dummy;
	}

	Node<T> *PushBack(T data) {
		Node<T> *new_node = new Node<T>(data);
		_PushBackNode(new_node);
		return new_node;
	}

	void PushBack(Node<T> *node) { _PushBackNode(node); }

	void Extract(Node<T> *node) {
		node->_Prev->_Next = node->_Next;
		node->_Next->_Prev = node->_Prev;
	}

	Node<T> PopFront() {
		Node<T> *front = _Dummy._Next;
		Extract(front);
		Node<T> res = *front;
		delete front;
		return res;
	}
};

class LRUCache {
	LinkedList<int> _Lst;
	std::vector<Node<int> *> _Key2Node;
	std::vector<int> _Key2Val;
	int _Remain;

public:
	LRUCache(int capacity)
	    : _Remain(capacity) {
		_Key2Node.resize(1'00'01);
		_Key2Val.resize(1'00'01);
	}

	int get(int key) {
		if (!_Key2Node[key]) {
			return -1;
		}
		_Lst.Extract(_Key2Node[key]);
		_Lst.PushBack(_Key2Node[key]);
		return _Key2Val[key];
	}

	void put(int key, int value) {
		if (_Key2Node[key]) {
			_Key2Val[key] = value;
			_Lst.Extract(_Key2Node[key]);
			_Lst.PushBack(_Key2Node[key]);
		} else {
			auto new_node = _Lst.PushBack(key);
			_Key2Node[key] = new_node;
			_Key2Val[key] = value;

			if (_Remain) {
				--_Remain;
			} else {
				auto node = _Lst.PopFront();
				_Key2Node[node._Data] = nullptr;
			}
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
