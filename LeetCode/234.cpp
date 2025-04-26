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
	bool isPalindrome(ListNode *head) {
		auto len = [](ListNode *curr) -> int {
			int res = 0;
			while (curr) {
				++res;
				curr = curr->next;
			}
			return res;
		};

		int n = len(head);
		if (n == 1) {
			return true;
		}

		ListNode *p = head;
		for (int i = 0; i < (n + 1) / 2; i++) {
			p = p->next;
		}

		ListNode *prev = nullptr;
		while (p) {
			auto nxt = p->next;
			p->next = prev;
			prev = p;
			p = nxt;
		}

		for (int i = 0; i < n / 2; i++) {
			if (head->val != prev->val) {
				return false;
			}
			head = head->next;
			prev = prev->next;
		}

		return true;
	}
};
