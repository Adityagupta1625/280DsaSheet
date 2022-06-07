// Sort list 
class Solution {
public:
    ListNode* findMid(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head->next;
        
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        
        return slow;
    }
    ListNode* merge(ListNode* left,ListNode* right){
        if(left==NULL) return right;
        
        if(right==NULL) return left;
        
        if(left->val<right->val){
            left->next=merge(left->next,right);
            return left;
        }
        else{
            right->next=merge(left,right->next);
            return right;
        }
        
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* mid=findMid(head);
        ListNode* tmp=mid->next;
        mid->next=NULL;
        
       
        ListNode* left=sortList(head);
        ListNode* right=sortList(tmp);
        
        
        return merge(left,right);
    }
};