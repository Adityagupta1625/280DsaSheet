#include <bits/stdc++.h>
using namespace std;

// O(n)+O(n) Stack and queue:
// Store the values in stack and queue then travers the stack and queue compare elements.

// Make a String from list and reverse it and check.

// O(n)+O(1) Solution:
class Solution {
public:
    ListNode* reverse(ListNode* head){
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
    bool isPalindrome(ListNode* head) {
        
        if(head==NULL || head->next==NULL) return head;
        
        ListNode* tmp=head;
        int cnt=0;
        
        while(tmp){
            cnt++;
            tmp=tmp->next;
        }
        
        int m=ceil(cnt/2);
        tmp=head;
        ListNode* prev=NULL;
        
        while(m!=0){
            prev=tmp;
            tmp=tmp->next;
           
            m--;
        }
        prev->next=NULL;
        
        tmp=reverse(tmp);
        

        while(head && tmp){
            
            if(head->val!=tmp->val) return false;
            
            head=head->next;
            tmp=tmp->next;
        }
        return true;
    }
};