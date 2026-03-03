#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

struct SegmentTreeNode {
	int tag;
	int value;
	int left_child;
	int right_child;
};

class SegmentTree {
private:
	int _length;
	std::vector<SegmentTreeNode> _nodes;

	int _alloc_left_node(int parent_node_id, int node_id) {
		if (node_id == -1) {
			int new_node_id = _nodes.size();
			_nodes[parent_node_id].left_child = new_node_id;
			_nodes.emplace_back(SegmentTreeNode{ 0, 0, -1, -1 });
			return new_node_id;
		}
		return node_id;
	}

	int _alloc_right_node(int parent_node_id, int node_id) {
		if (node_id == -1) {
			int new_node_id = _nodes.size();
			_nodes[parent_node_id].right_child = new_node_id;
			_nodes.emplace_back(SegmentTreeNode{ 0, 0, -1, -1 });
			return new_node_id;
		}
		return node_id;
	}

	void _set(int left, int right, int tree_left, int tree_right, int node_id) {
		if (left <= tree_left && tree_right <= right) {
			_nodes[node_id].tag = 1;
			_nodes[node_id].value = tree_right - tree_left + 1;
			return;
		}
		_pushdown(tree_left, tree_right, node_id);
		int mid = (tree_left + tree_right) >> 1;
		int left_child = _alloc_left_node(node_id, _nodes[node_id].left_child);
		int right_child = _alloc_right_node(node_id, _nodes[node_id].right_child);
		if (left <= mid) {
			_set(left, right, tree_left, mid, left_child);
		}
		if (right > mid) {
			_set(left, right, mid + 1, tree_right, right_child);
		}
		_nodes[node_id].value = _nodes[left_child].value + _nodes[right_child].value;
	}

	int _query(int left, int right, int tree_left, int tree_right, int node_id) {
		if (left <= tree_left && tree_right <= right) {
			return _nodes[node_id].value;
		}
		_pushdown(tree_left, tree_right, node_id);
		int mid = (tree_left + tree_right) >> 1;
		int left_child = _alloc_left_node(node_id, _nodes[node_id].left_child);
		int right_child = _alloc_right_node(node_id, _nodes[node_id].right_child);
		int res = 0;
		if (left <= mid) {
			res += _query(left, right, tree_left, mid, left_child);
		}
		if (right > mid) {
			res += _query(left, right, mid + 1, tree_right, right_child);
		}
		return res;
	}

	void _pushdown(int tree_left, int tree_right, int node_id) {
		if (tree_left != tree_right && _nodes[node_id].tag != 0) {
			int mid = (tree_left + tree_right) >> 1;
			int left_child = _alloc_left_node(node_id, _nodes[node_id].left_child);
			int right_child = _alloc_right_node(node_id, _nodes[node_id].right_child);
			_nodes[left_child].tag = 1;
			_nodes[left_child].value = mid - tree_left + 1;
			_nodes[right_child].tag = 1;
			_nodes[right_child].value = tree_right - mid;
			_nodes[node_id].tag = 0;
		}
	}

public:
	explicit SegmentTree(int length)
	    : _length(length) {
		_nodes.emplace_back(SegmentTreeNode{ 0, 0, -1, -1 });
	}

	void set(int left, int right) {
		_set(left, right, 1, _length, 0);
	}

	int query(int left, int right) {
		return _query(left, right, 1, _length, 0);
	}
};

void solve() {
	int n = 0;
	int q = 0;
	std::cin >> n >> q;

	SegmentTree seg_tree(n);

	for (int i = 0; i < q; i++) {
		int left = 0;
		int right = 0;
		std::cin >> left >> right;

		seg_tree.set(left, right);
		std::cout << n - seg_tree.query(1, n) << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	preprocess();

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
