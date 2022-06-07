// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.

 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return NULL;
        ListNode* ptr=head->next;
        ListNode* prev=head;
         ListNode* tmp;
        while(ptr!=NULL){
            if(prev->val==ptr->val){
                prev->next=ptr->next;
                ptr=ptr->next;
            }
            else{
                prev=prev->next;
                ptr=ptr->next;
            }
            
        }
        return head;
    }
    
};