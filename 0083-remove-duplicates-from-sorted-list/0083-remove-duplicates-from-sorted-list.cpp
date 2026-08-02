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
    ListNode* deleteDuplicates(ListNode* head) {
    if(head!=NULL && head->next!=NULL){
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=NULL && slow!=NULL){
            if(slow->val==fast->val){
                slow->next=slow->next->next; 
                fast=fast->next; 
            }
            else{
                slow=slow->next;
                fast=fast->next;
            }
            
        }
      }
        return head;
    }
};