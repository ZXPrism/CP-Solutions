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
class Solution {
public:
	ListNode *removeNthFromEnd(ListNode *head, int n) {
		ListNode *p = head, *q = head;
		for (int i = 0; i < n - 1; i++) {
			p = p->next;
		}

		ListNode *r = nullptr;
		while (p->next) {
			p = p->next;
			r = q;
			q = q->next;
		}

		if (!r) {
			return head->next;
		} else {
			r->next = q->next;
		}

		return head;
	}
};
