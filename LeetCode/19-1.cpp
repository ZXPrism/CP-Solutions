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
		ListNode *dummy = new ListNode(114514);
		dummy->next = head;

		ListNode *p = head, *q = dummy;
		for (int i = 0; i < n - 1; i++) {
			p = p->next;
		}
		while (p->next) {
			p = p->next;
			q = q->next;
		}
		q->next = q->next->next;

		return dummy->next;
	}
};
