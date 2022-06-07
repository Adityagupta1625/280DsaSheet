// Given the head of a linked list and an integer val, remove all the nodes of the linked list that has Node.val == val, and return the new head.

// Input: head = [1,2,6,3,4,5,6], val = 6
// Output: [1,2,3,4,5]

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* p=head;
        ListNode* prev;
        if(head==NULL){
            return NULL;
        }
        while(p!=NULL){
            if(p==head && p->val==val){
                head=head->next;
            }
            else if(p->val==val){
                prev->next=p->next;
                p=p->next;
            }
            else{
                 prev=p;
                 p=p->next;
            }
           
        }
        return head;
    }
};