/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode *header = NULL;
		ListNode *tmp = NULL;
		ListNode *last = NULL;
		int sum = 0;
		int n = 0;
		int num = 0;
		while(l1 && l2) {
			sum = l1->val + l2->val + n;
			num = sum % 10;
			n = sum / 10;

			if (!header) {
				header = new ListNode(num);
				tmp = header;
			} else {
				last = new ListNode(num);
				tmp->next = last;
				tmp = tmp->next;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
		if (l1 == NULL) {
			while(l2) {
				sum = l2->val + n;
				num = sum % 10;
				n = sum / 10;

				if (!header) {
					header = new ListNode(num);
					tmp = header;
				} else {
					last = new ListNode(num);
					tmp->next = last;
					tmp = tmp->next;
				}
				l2 = l2->next;
			}
		} else {
			while(l1) {
				sum = l1->val + n;

				num = sum % 10;
				n = sum / 10;

				if (!header) {
					header = new ListNode(num);
					tmp = header;
				} else {
					last = new ListNode(num);
					tmp->next = last;
					tmp = tmp->next;
				}
				l1 = l1->next;
			}
		}
		if (n)
			tmp->next = new ListNode(n);
		return header;

	}
};
