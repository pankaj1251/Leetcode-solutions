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
    Node* flatten(Node* head) {
        for(Node* h=head; h != NULL; h=h->next){
            if(h->child){
                Node* next = h->next;
                h->next = h->child;
                h->next->prev = h;
                h->child=NULL;

                Node* ptr = h->next;
                while(ptr->next)ptr=ptr->next;
                ptr->next = next;
                
                if(next)next->prev=ptr;
            }
        }

        return head;
    }
};