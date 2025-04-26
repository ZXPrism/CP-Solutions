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
	ListNode *swapPairs(ListNode *head) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		ListNode *prev = dummy;
		while (head && head->next) {
			auto nxt = head->next->next;

			auto left = head, right = head->next;
			left->next = nxt;
			right->next = left;
			prev->next = right;

			prev = left;
			head = nxt;
		}

		return dummy->next;
	}
};
