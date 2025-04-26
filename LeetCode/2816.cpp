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
	ListNode *doubleIt(ListNode *head) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *prev = dummy;
		while (head) {
			head->val <<= 1;
			if (head->val >= 10) {
				head->val -= 10;
				++prev->val;
			}
			prev = head;
			head = head->next;
		}
		return (dummy->val ? dummy : dummy->next);
	}
};
