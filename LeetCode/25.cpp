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
	ListNode *reverseKGroup(ListNode *head, int k) {
		ListNode *dummy = new ListNode(0);
		dummy->next = head;

		int len = 0;
		ListNode *p = head;
		while (p) {
			++len;
			p = p->next;
		}

		ListNode *p0 = dummy, *curr = head;
		int cnt = len / k;
		for (int i = 0; i < cnt; i++) {
			ListNode *prev = nullptr;

			for (int j = 0; j < k; j++) {
				ListNode *nxt = curr->next;
				curr->next = prev;
				prev = curr;
				curr = nxt;
			}

			ListNode *beg = p0->next;
			beg->next = curr;
			p0->next = prev;
			p0 = beg;
		}

		return dummy->next;
	}
};
