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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
       
      
        int carry=0;
        while(temp1 ||temp2||carry){
            int val1=(temp1)?temp1->val:0;
            int val2=(temp2)?temp2->val:0;
                       

            int sum=val1 + val2 + carry;
        
                carry=sum/10;
                int x=sum%10;
                current->next=new ListNode(x);
                current=current->next;
              
            

            if(temp1){
            temp1=temp1->next;
            }
            if(temp2){
                temp2=temp2->next;
            }
        }
        return dummyHead->next;
    }
};
