// You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given.
// Note: No head reference is given to you. It is guaranteed that the node to be deleted is not a tail node in the linked list.

// Example 1:

// Input:
// N = 2
// value[] = {1,2}
// node = 1
// Output: 2
// Explanation: After deleting 1 from the
// linked list, we have remaining nodes
// as 2.
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to delete a node without any reference to head pointer.
    
    //O(n) Solution:
    void deleteNode(Node *del)
    {
        if (del == NULL)
            return;

        if (del->next == NULL)
        {
            del = NULL;
            return;
        }

        Node *prev = NULL;
        while (del->next != NULL)
        {
            del->data = del->next->data;
            prev = del;
            del = del->next;
        }
        prev->next = NULL;
    }
};

// O(1) Solution:
void deleteNode(Node *del)
{
    *del = *(del->next);
}