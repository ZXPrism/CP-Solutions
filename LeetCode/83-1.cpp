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
		ListNode *p = head;
		while (p->next) {
			if (p->val == p->next->val) {
				p->next = p->next->next;
			} else {
				p = p->next;
			}
		}
		return head;
	}
};
