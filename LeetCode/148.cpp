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
	ListNode *sortList(ListNode *head) {
		auto Mid = [](ListNode *p) {
			ListNode *slow = p, *fast = p, *prev = nullptr;
			while (fast && fast->next) {
				prev = slow;
				slow = slow->next;
				fast = fast->next->next;
			}
			prev->next = nullptr;
			return slow;
		};

		auto Merge = [](ListNode *lst1, ListNode *lst2) {
			ListNode dummy, *curr = &dummy;
			while (lst1 && lst2) {
				if (lst1->val < lst2->val) {
					curr->next = lst1;
					curr = lst1;
					lst1 = lst1->next;
				} else {
					curr->next = lst2;
					curr = lst2;
					lst2 = lst2->next;
				}
			}
			curr->next = (lst1 ? lst1 : lst2);
			return dummy.next;
		};

		auto MergeSort = [&](this auto &&MergeSort, ListNode *p) -> ListNode * {
			if (p && p->next) {
				ListNode *mid = Mid(p);
				auto lst1 = MergeSort(p);
				auto lst2 = MergeSort(mid);
				return Merge(lst1, lst2);
			}
			return p;
		};

		return MergeSort(head);
	}
};
