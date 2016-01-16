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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL)
			return NULL;
		ListNode* fast = head;
		ListNode* normal = head;
		ListNode* slow = head;
		while (--n > 0) {
			fast = fast->next;
		}
		if(fast->next) {
			fast = fast->next;
			normal = normal->next;
		}
		while(fast->next) {
			slow = slow->next;
			fast = fast->next;
			normal = normal->next;
		}
		if (slow == fast) {
			delete head;
			return NULL;
		} else if (slow == normal) {
			head = head->next;
			delete slow;
			return head;
		}
		slow->next = normal->next;
		delete normal;
		return head;
	}
};