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
	ListNode *reverseBetween(ListNode *head, int left, int right) {
		auto sentinel = new ListNode(0), p0 = sentinel;
		sentinel->next = head;

		for (int i = 0; i < left - 1; i++) {
			p0 = p0->next;
		}

		ListNode *curr = p0->next, *prev = nullptr;
		for (int i = 0; i < right - left + 1; i++) {
			auto nxt = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nxt;
		}

		p0->next->next = curr;
		p0->next = prev;

		return sentinel->next;
	}
};
