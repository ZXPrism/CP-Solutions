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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		auto reverse = [](ListNode *head) -> ListNode * {
			ListNode *prev = nullptr;
			while (head) {
				auto nxt = head->next;
				head->next = prev;
				prev = head;
				head = nxt;
			}
			return prev;
		};
		l1 = reverse(l1);
		l2 = reverse(l2);
		auto res = new ListNode(0), l3 = res;
		int carry = 0;
		while (l1 || l2) {
			l3->next = new ListNode(0);
			l3 = l3->next;
			l3->val = carry;
			carry = 0;
			if (l1) {
				l3->val += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				l3->val += l2->val;
				l2 = l2->next;
			}
			if (l3->val >= 10) {
				l3->val -= 10;
				++carry;
			}
		}
		if (carry) {
			l3->next = new ListNode(0);
			l3 = l3->next;
			l3->val = carry;
		}
		return reverse(res->next);
	}
};
