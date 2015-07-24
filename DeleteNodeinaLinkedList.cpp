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
    void deleteNode(ListNode* node) {
        // Because except the tail, so replace the one we need to delete.
        ListNode *tmp = node->next;
        node->val = node->next->val;
        node->next = node->next->next;
        delete tmp;
    }
};
