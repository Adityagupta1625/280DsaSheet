// Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* slow=headA,*fast=headB;
        if(slow==fast) return slow;
        
        if(slow==NULL || fast==NULL) return NULL;
        
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
            if(slow==fast) return slow;
            
             if(fast==NULL) fast=headA;
            
            if(slow==NULL) slow=headB;
           
        }
        if(slow==fast) return slow;
        return NULL;
    }
};