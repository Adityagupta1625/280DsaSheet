// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

#include <bits/stdc++.h>
using namespace std;

// using stack:
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        
        ListNode* tmp=head;
        while(tmp!=NULL){
            st.push(tmp);
            tmp=tmp->next;
        }
        
        tmp=head;
        int num=st.size();
        while(st.size()>num/2){
            ListNode* v=st.top();
            st.pop();
            
            v->next=tmp->next;
            
            tmp->next=v;
            
            tmp=v->next;
        }
        tmp->next=NULL;
        head=tmp;
    }
};

// O(n) Solution:

class Solution {
public:
    ListNode* getMid(ListNode* head){
        ListNode* slow=head,*fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        return slow;
    }
     ListNode* reverse(ListNode* head) {
        ListNode* prev=NULL;
        ListNode* curr=head,*next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode* mid=getMid(head);
        ListNode* p2=mid->next;
        mid->next=NULL;
        p2=reverse(p2);
        
        
        ListNode* ptr=head;
        
        while(p2 && ptr){
            ListNode* tmp=p2->next;
            p2->next=ptr->next;
            ptr->next=p2;
            p2=tmp;
            ptr=ptr->next->next;
        }
    }
};