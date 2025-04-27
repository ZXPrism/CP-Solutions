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
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head) {
			return nullptr;
		}
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode *p = dummy;
		while (p->next) {
			ListNode *q = p->next;
			if (q->next && q->val == q->next->val) {
				int val = q->val;
				while (q && q->val == val) {
					q = q->next;
				}
				p->next = q;
			} else {
				p = q;
			}
		}

		return dummy->next;
	}
};
