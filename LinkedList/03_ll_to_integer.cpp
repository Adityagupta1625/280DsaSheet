// Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.

// Return the decimal value of the number in the linked list.

// Input: head = [1,0,1]
// Output: 5
// Explanation: (101) in base 2 = (5) in base 10


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int num=0;
        while(head!=NULL){
            num=num*2+head->val;
            head=head->next;
        }
        return num;
    }
};