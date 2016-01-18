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
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next)
            return head;

        ListNode *odd = head;
        ListNode *even = head->next;
        ListNode *oddTmp = even->next, *evenTmp = even;
        odd->next = oddTmp;

        while (oddTmp) {
            evenTmp->next = oddTmp->next;
            evenTmp = evenTmp->next;
            if (evenTmp) {
                oddTmp->next = evenTmp->next;
            } else {
                oddTmp->next = even;
                break;
            }
            if (!(oddTmp->next)) {
                oddTmp->next = even;
                break;
            } else {
                oddTmp = oddTmp->next;
            }
        }

        return head;
    }
};