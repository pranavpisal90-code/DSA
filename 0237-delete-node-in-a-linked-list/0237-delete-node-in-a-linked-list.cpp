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
        int x=node->next->val;
        ListNode* temp=node;
        node->val=x;
        node->next=node->next->next;
        
        
     
    }
};