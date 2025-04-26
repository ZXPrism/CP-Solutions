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
		ListNode *res = new ListNode(0);
		ListNode *root = res;
		int carry = 0;

		while (l1 || l2) {
			res->next = new ListNode(0);
			res = res->next;
			res->val = carry;

			if (l1) {
				res->val += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				res->val += l2->val;
				l2 = l2->next;
			}

			carry = 0;
			if (res->val >= 10) {
				res->val -= 10;
				++carry;
			}
		}

		if (carry) {
			res->next = new ListNode(0);
			res = res->next;
			res->val = 1;
		}

		return root->next;
	}
};
