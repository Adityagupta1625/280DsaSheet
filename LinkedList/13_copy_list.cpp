// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL)
            return head;
        
        Node* ptr=head;
        
        while(ptr!=NULL){
            Node* tmp=new Node(ptr->val);
            tmp->next=ptr->next;
            ptr->next=tmp;
            ptr=tmp->next;
        }
        
        ptr=head;
        while(ptr!=NULL){
            if(ptr->random!=NULL)
                ptr->next->random=ptr->random->next;
            else if(ptr->random==NULL)
                ptr->next->random=NULL;
             ptr=ptr->next->next;   
        }
        
        Node* curr=head;
        ptr=head->next;
        Node* ans=ptr;
        
        while(curr->next->next!=NULL){
            curr->next=curr->next->next;
            ptr->next=ptr->next->next;
            curr=curr->next;
            ptr=ptr->next;
        }
        curr->next=NULL;
        ptr->next=NULL;
        return ans;
    }
};


// using hashmap:
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> m;
        
        Node* tmp=head;
        while(tmp!=NULL){
            Node* ans=new Node(tmp->val);
            m[tmp]=ans;
            tmp=tmp->next;
        }
        
        tmp=head;
        while(tmp!=NULL){
            Node* ans=m[tmp];
            ans->next=m[tmp->next];
            ans->random=m[tmp->random];
            tmp=tmp->next;
        }
        return m[head];
    }
};