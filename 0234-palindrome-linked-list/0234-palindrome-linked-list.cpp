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
    bool isPalindrome(ListNode* head) {
    vector<int> v1;
       bool x=true;
       if(head!=NULL){
        ListNode* temp=head;
        
        while(temp->next!=NULL){
            v1.push_back(temp->val);
            temp=temp->next;
     
        }
        v1.push_back(temp->val);

        int i=0;
        int j=v1.size()-1;
        while(i<j){
            if(v1[i]==v1[j]){
                x=true;
                i++;
                j--;
            }
            else{
                x=false;
                break;
            }
        }
       }
        if(head->next==NULL){
            x=true;
        }
        return x;
    }
};