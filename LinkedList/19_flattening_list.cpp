// Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
// (i) a next pointer to the next node,
// (ii) a bottom pointer to a linked list where this node is head.
// Each of the sub-linked-list is in sorted order.
// Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order. 
// Note: The flattened list will be printed using the bottom pointer instead of next pointer.

// merge approach:

Node* merge(Node* p,Node* q){
    if(p==NULL) return q;
    
    if(q==NULL) return p;

    if(p->data<q->data){
        p->bottom=merge(p->bottom,q);
        return p;
    }
    else{
        q->bottom=merge(p,q->bottom);
        return q;
    }
    
}
Node *flatten(Node *root)
{
   // Your code here
   Node* ptr=root;
   root=root->next;
   
   while(root){
     ptr=merge(ptr,root);
     root=root->next;
   }
   return ptr;
}


// priority queue
struct cmp{
  bool operator()(Node* a,Node* b){
      return a->data>b->data;
  }  
};
Node *flatten(Node *root)
{
   // Your code here
   Node* ptr=root;
   priority_queue<Node*,vector<Node*>,cmp> pq;
   
   while(ptr!=NULL){
       pq.push(ptr);
       ptr=ptr->next;
   }
   Node* ans=NULL,*prev=NULL;
  
   while(!pq.empty()){
       Node* tmp=pq.top();
       pq.pop();
       
       
       if(ans==NULL){
           ans=new Node(tmp->data);
           prev=ans;
       }
       else{
           prev->bottom=new Node(tmp->data);
           prev=prev->bottom;
       }
       
       if(tmp->bottom){
           pq.push(tmp->bottom);
       }
       
   }
   
 
   return ans;
}