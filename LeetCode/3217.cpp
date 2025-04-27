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
	ListNode *modifiedList(vector<int> &nums, ListNode *head) {
		std::unordered_set<int> target(nums.begin(), nums.end());
		ListNode *dummy = new ListNode(0);
		dummy->next = head;
		ListNode *p = dummy;
		while (p->next) {
			if (target.contains(p->next->val)) {
				p->next = p->next->next;
			} else {
				p = p->next;
			}
		}
		return dummy->next;
	}
};
