// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// O(n) approach:

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        
        l1=reverse(l1);
        l2=reverse(l2);
        
        ListNode* l3=NULL,*prev=NULL;
        while(l1!=NULL && l2!=NULL){
            int s=carry+l1->val+l2->val;
            if(l3==NULL){
                l3=new ListNode(s%10);
                prev=l3;
            }
            else{
                prev->next=new ListNode(s%10);
                prev=prev->next;
            }
            carry=s/10;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int s=carry+l1->val;
            if(l3==NULL){
                l3=new ListNode(s%10);
                prev=l3;
            }
            else{
                prev->next=new ListNode(s%10);
                prev=prev->next;
            }
            carry=s/10;
            l1=l1->next;
        }
        while(l2!=NULL){
            int s=carry+l2->val;
            if(l3==NULL){
                l3=new ListNode(s%10);
                prev=l3;
            }
            else{
                prev->next=new ListNode(s%10);
                prev=prev->next;
            }
            carry=s/10;
            l2=l2->next;
        }
        while(carry){
            prev->next=new ListNode(carry%10);
            prev=prev->next;
            carry=carry/10;
        }
        l3=reverse(l3);
        return l3;
    }
};

// recursion:
class Solution {
public:
    int add(ListNode* one ,ListNode* two ,int sone,int stwo,ListNode* &t){
        if(sone==0&&stwo==0)
            return 0;    
        int carry;
        int t1=0,t2=0;
        if(sone>stwo)
        {
            carry=add(one->next,two,sone-1,stwo,t);
            t1=one->val;
        }else if(sone<stwo){
            carry=add(one,two->next,sone,stwo-1,t);
            t2=two->val;
        }else{
            carry=add(one->next,two->next,sone-1,stwo-1,t);
            t1=one->val;
            t2=two->val;
        }
        int data = t1+t2+carry;
        ListNode* nn = new ListNode(data%10);
        nn->next=t;
        t=nn;
        return data/10;
    }
    
    ListNode* addTwoNumbers(ListNode* one, ListNode* two) {
        ListNode* t= one;
        int sone=0;
        while(t!=NULL){
            sone++;
            t=t->next;
        }
        t=two;
        int stwo=0;
        while(t!=NULL){
            stwo++;
            t=t->next;
        }
        t=NULL;
        int carry = add(one,two,sone,stwo,t);
        if(carry){
            ListNode* nn = new ListNode(carry);
            nn->next=t;
            t=nn;
        }
        return t;
    }
};

// we can use stack also.