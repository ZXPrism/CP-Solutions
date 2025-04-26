/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
	Node *copyRandomList(Node *head) {
		std::unordered_map<Node *, Node *> hashmap;
		Node *dummy = new Node(0);
		Node *p = head, *q = dummy;

		while (p) {
			q->next = new Node(p->val);
			hashmap[p] = q->next;
			q = q->next;
			p = p->next;
		}

		p = head, q = dummy->next;
		while (p) {
			q->random = hashmap[p->random];
			q = q->next;
			p = p->next;
		}

		return dummy->next;
	}
};
