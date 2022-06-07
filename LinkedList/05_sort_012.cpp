// Given a linked list of N nodes where nodes can contain values 0s, 1s, and 2s only. The task is to segregate 0s, 1s, and 2s linked list such that all zeros segregate to head side, 2s at the end of the linked list, and 1s in the mid of 0s and 2s.

// Example 1:

// Input:
// N = 8
// value[] = {1,2,2,1,2,0,2,2}
// Output: 0 1 1 2 2 2 2 2
// Explanation: All the 0s are segregated
// to the left end of the linked list,
// 2s to the right end of the list, and
// 1s in between.
#include <bits/stdc++.h>
using namespace std;

Node* segregate(Node *head) {
        int count[]={0,0,0};
        
        Node * ptr=head;
        
        while(ptr!=NULL){
            count[ptr->data]++;
            ptr=ptr->next;
        }
        
        int total_cnt=0;
        for(int i=0;i<3;i++)
            total_cnt+=count[i];
        
        int j=0;
        ptr=head;
        while(ptr!=NULL){
            if(count[j]==0)
                j++;
            else{
                count[j]--;
                ptr->data=j;
                ptr=ptr->next;
            }
        }
        return head;
    }
