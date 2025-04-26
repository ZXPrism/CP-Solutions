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
	void reorderList(ListNode *head) {
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode *prev = nullptr;
		while (slow) {
			auto nxt = slow->next;
			slow->next = prev;
			prev = slow;
			slow = nxt;
		}

		ListNode *p = head, *q = prev;
		while (q->next) {
			ListNode *nxt1 = p->next, *nxt2 = q->next;
			p->next = q;
			q->next = nxt1;
			p = nxt1;
			q = nxt2;
		}
	}
};
