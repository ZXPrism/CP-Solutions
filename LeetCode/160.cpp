/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		auto len = [](ListNode *head) -> int {
			int res = 0;
			while (head) {
				++res;
				head = head->next;
			}
			return res;
		};
		int m = len(headA), n = len(headB);
		if (m > n) {
			std::swap(headA, headB);
			std::swap(m, n);
		}
		for (int i = 0; i < n - m; i++) {
			headB = headB->next;
		}
		for (int i = 0; i < m; i++) {
			if (headA == headB) {
				return headA;
			}
			headA = headA->next;
			headB = headB->next;
		}
		return nullptr;
	}
};
