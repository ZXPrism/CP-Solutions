template<typename T>
class SegmentTree {

	struct Info {
		T _Data = 0;
		T _Tag = 0;
	};

	template<typename NodeType>
	struct Node {
		NodeType _Val;
		int _Left = -1;
		int _Right = -1;
	};

	template<typename NodeType>
	class NodePool {
	private:
		std::vector<Node<NodeType>> _Pool;

	public:
		NodePool() {
			_Pool.resize(1);
		}

		Node<NodeType> &operator[](int idx) {
			return _Pool[idx];
		}

		int alloc(int idx) {
			if (idx == -1) {
				idx = _Pool.size();
				_Pool.emplace_back();
			}
			return idx;
		}
	};

private:
	int _N;
	T _MOD;
	NodePool<Info> _Data;

public:
	explicit SegmentTree(const std::vector<T> &initial_values, T mod)
	    : _N(initial_values.size())
	    , _MOD(mod) {
		_build_tree(initial_values, 1, _N, 0);
	}

	void add(int left, int right, T x) {
		_add(left, right, x, 1, _N, 0);
	}

	T qry_sum(int left, int right) {
		return _qry_sum(left, right, 1, _N, 0);
	}

private:
	void _build_tree(const std::vector<T> &initial_values, int left, int right, int node_id) {
		if (left == right) {
			_Data[node_id]._Val._Data = initial_values[left - 1];
			return;
		}
		int mid = (left + right) >> 1;
		_Data[node_id]._Left = _Data.alloc(_Data[node_id]._Left);
		_Data[node_id]._Right = _Data.alloc(_Data[node_id]._Right);
		int lchild = _Data[node_id]._Left, rchild = _Data[node_id]._Right;
		_build_tree(initial_values, left, mid, lchild);
		_build_tree(initial_values, mid + 1, right, rchild);
		_Data[node_id]._Val._Data = _Data[lchild]._Val._Data + _Data[rchild]._Val._Data;
	}

	void _add(int left, int right, T x, int _left, int _right, int _node_id) {
		if (left <= _left && _right <= right) {
			_Data[_node_id]._Val._Data += (_right - _left + 1) * x;
			_Data[_node_id]._Val._Tag += x;
			return;
		}

		_Data[_node_id]._Left = _Data.alloc(_Data[_node_id]._Left);
		_Data[_node_id]._Right = _Data.alloc(_Data[_node_id]._Right);
		int lchild = _Data[_node_id]._Left, rchild = _Data[_node_id]._Right;
		_pushdown(_left, _right, _node_id);

		int mid = (_left + _right) >> 1;
		if (left <= mid) {
			_add(left, right, x, _left, mid, lchild);
		}
		if (right > mid) {
			_add(left, right, x, mid + 1, _right, rchild);
		}
		_Data[_node_id]._Val._Data = _Data[lchild]._Val._Data + _Data[rchild]._Val._Data;
	}

	T _qry_sum(int left, int right, int _left, int _right, int _node_id) {
		if (left <= _left && _right <= right) {
			return _Data[_node_id]._Val._Data;
		}
		_Data[_node_id]._Left = _Data.alloc(_Data[_node_id]._Left);
		_Data[_node_id]._Right = _Data.alloc(_Data[_node_id]._Right);
		int lchild = _Data[_node_id]._Left, rchild = _Data[_node_id]._Right;
		_pushdown(_left, _right, _node_id);

		T res{};
		int mid = (_left + _right) >> 1;
		if (left <= mid) {
			res += _qry_sum(left, right, _left, mid, lchild);
		}
		if (right > mid) {
			res += _qry_sum(left, right, mid + 1, _right, rchild);
		}
		return res;
	}

	void _pushdown(int left, int right, int node_id) {
		if (_Data[node_id]._Val._Tag && left != right) {
			int mid = (left + right) >> 1;
			int lchild = _Data[node_id]._Left, rchild = _Data[node_id]._Right;
			_Data[lchild]._Val._Data += (mid - left + 1) * _Data[node_id]._Val._Tag;
			_Data[rchild]._Val._Data += (right - mid) * _Data[node_id]._Val._Tag;
			_Data[lchild]._Val._Tag += _Data[node_id]._Val._Tag;
			_Data[rchild]._Val._Tag += _Data[node_id]._Val._Tag;
			_Data[node_id]._Val._Tag = 0;
		}
	}
};
