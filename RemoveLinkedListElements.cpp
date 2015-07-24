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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head)
		    return head;
	    ListNode *tmp, *del_node;
	    static ListNode list_head(-1);
	    list_head.next = head;
	    tmp = &list_head;

	    while (tmp->next) {
		    if (tmp->next->val == val) {
			    del_node = tmp->next;
			    tmp->next = tmp->next->next;
				delete del_node;
		    } else {
			    tmp = tmp->next;
		    }
	    }
	    return list_head.next;
    }
};
