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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL|| k==0){
            return head;
        }
        int count=0;
        ListNode* temp=head;
        ListNode* prev=NULL;
        while(temp->next!=NULL){
            temp=temp->next;
            count++;
        }
       temp->next=head;
       count++;
       k=k%count;
       temp=head;
       while(count-k!=0){
        prev=temp;
        temp=temp->next;
        count--;
       }
       prev->next=NULL;
       head=temp;
return head;

    }
};