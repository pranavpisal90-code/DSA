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
    ListNode* reverseList(ListNode* head) {
        // stack<int> s1;

        // ListNode* temp=head;
        // while(temp){
        //     s1.push(temp->val);
        //     temp=temp->next;
        // }
 
        // ListNode* temp2=head;
        // while(temp2){
        
        //     temp2->val=s1.top();
        //     s1.pop();
        //     temp2=temp2->next;
        // }
        // return head;
    if(!head){return head;}
    ListNode* curr=head->next;
    ListNode* prev=head;

    ListNode* temp=head;

    while(temp && curr){
        temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head->next=NULL;
    return prev;

    }
};


    
