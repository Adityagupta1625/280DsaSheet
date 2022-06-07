// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode* tmp=new ListNode(-1);
        ListNode* p=tmp;
        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            carry=sum/10;
            p->next=new ListNode(sum%10);
            p=p->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            int sum=carry+l1->val;
            p->next=new ListNode(sum%10);
            p=p->next;
            carry=sum/10;
            l1=l1->next;
        }
        while(l2){
            int sum=carry+l2->val;
            p->next=new ListNode(sum%10);
            p=p->next;
            carry=sum/10;
            l2=l2->next;
        }
        while(carry){
            p->next=new ListNode(carry%10);
            p=p->next;
            carry=carry/10;
        }
        return tmp->next;
    }
};