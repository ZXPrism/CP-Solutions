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
		if (!head || !head->next) {
			return head;
		}
		ListNode *left = head, *right = head->next;
		auto nxt = swapPairs(right->next);
		right->next = left;
		left->next = nxt;
		return right;
	}
};
