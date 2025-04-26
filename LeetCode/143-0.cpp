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
		ListNode *slow = head, *fast = head, *prev = nullptr;
		while (fast && fast->next) {
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		if (prev) {
			prev->next = nullptr;
		} else {
			return;
		}

		prev = nullptr;
		while (slow) {
			auto nxt = slow->next;
			slow->next = prev;
			prev = slow;
			slow = nxt;
		}

		ListNode *p = head, *q = prev, *dummy = new ListNode(0);
		int flag = 1;
		while (p || q) {
			if (flag && p) {
				dummy->next = p;
				dummy = p;
				p = p->next;
			} else {
				dummy->next = q;
				dummy = q;
				q = q->next;
			}
			flag ^= 1;
		}
	}
};
