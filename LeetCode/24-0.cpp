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
		if (!head) {
			return nullptr;
		}

		ListNode *prev = nullptr, *pprev = nullptr;
		ListNode *r1 = head, *r2 = head->next;

		int cnt = 0;

		while (head) {
			auto nxt = head->next;
			++cnt;
			if (~cnt & 1) {
				if (pprev) {
					pprev->next = head;
				}
				head->next = prev;
				prev->next = nxt;
				pprev = head;
			} else {
				pprev = prev;
				prev = head;
			}

			head = nxt;
		}

		return cnt >= 2 ? r2 : r1;
	}
};
