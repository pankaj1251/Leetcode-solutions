/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    //first see ITERATIVE approach.
    Node* func(Node* head, Node* temp){
        if(!head)return temp;

        head->next = func(head->child, func(head->next, temp));
        if(head->next)head->next->prev = head;

        head->child = NULL;
        return head;
    }
    Node* flatten(Node* head) {
        return func(head, NULL);
    }
};