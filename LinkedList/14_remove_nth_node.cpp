// Given the head of a linked list, remove the nth node from the end of the list and return its head.

// Brute Force:
// Reverse the list and remove kth node then again reverse the list.
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL) return head;
        
        ListNode* slow=head,*fast=head;
        
        while(n){
            fast=fast->next;
            n--;
        }
        if(!fast) return slow->next;
        
        while(fast->next!=NULL){
            slow=slow->next;
            fast=fast->next;
        }
        slow->next=slow->next->next;
        return head;
    }
};