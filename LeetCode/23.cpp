/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

struct Node {
	ListNode *_Node;
	Node(ListNode *node)
	    : _Node(node) {}
	bool operator<(const Node &rhs) const {
		return _Node->val > rhs._Node->val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		ListNode dummy(0, nullptr), *curr = &dummy;

		std::priority_queue<Node> min_heap;
		for (auto head : lists) {
			if (head) {
				min_heap.push(head);
			}
		}

		while (min_heap.size() > 1) {
			auto [node] = min_heap.top();
			min_heap.pop();

			if (node->next) {
				min_heap.push(node->next);
			}

			curr->next = node;
			curr = node;
		}
		if (!min_heap.empty()) {
			curr->next = min_heap.top()._Node;
		}

		return dummy.next;
	}
};
