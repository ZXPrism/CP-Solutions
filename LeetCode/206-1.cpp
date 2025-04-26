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
	ListNode *reverseList(ListNode *head) {
		auto dfs = [&](this auto &&dfs, ListNode *prev,
		               ListNode *curr) -> ListNode * {
			if (!curr) {
				return prev;
			}
			auto nxt = curr->next;
			curr->next = prev;
			return dfs(curr, nxt);
		};
		return dfs(nullptr, head);
	}
};
