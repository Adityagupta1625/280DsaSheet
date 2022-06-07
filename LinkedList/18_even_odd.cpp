// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.

// Example 1:

// Input: 
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers 
// so they appear first and 17,15,9 are odd 
// numbers that appear later
class Solution{
public:
    Node* divide(int N, Node *head){
        // code here
        Node* end=head;
        
        while(end->next!=NULL){
            end=end->next;
        }
        Node* last=end;
        
        while(head->data%2==1 && head!=last->next){
            end->next=new Node(head->data);
            end=end->next;
            head=head->next;
        }
        
        Node* ptr=head,*prev;
        while(ptr!=last->next){
            if(ptr->data%2==1){
                end->next=new Node(ptr->data);
                end=end->next;
                prev->next=ptr->next;
                ptr=ptr->next;
            }
            else{
                prev=ptr;
                ptr=ptr->next;
            }
        }
        return head;
    }
};