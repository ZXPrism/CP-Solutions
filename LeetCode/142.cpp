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
	ListNode *detectCycle(ListNode *head) {
		// slow: a + b
		// fast: 2(a + b) = a + b + k * (b + c)
		// a + b = k * (b + c), k >= 1
		// a + b - b - c = a - c = (k - 1) * (b + c)
		ListNode *slow = head, *fast = head;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				fast = head;
				while (fast != slow) {
					slow = slow->next;
					fast = fast->next;
				}
				return slow;
			}
		}
		return nullptr;
	}
};
