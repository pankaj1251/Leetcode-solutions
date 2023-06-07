/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast=head, *slow=head;

        while(fast and fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *prev=slow, *nxt;
        slow=slow->next;
        prev->next=NULL;

        while(slow!=NULL){
            nxt=slow->next;
            slow->next = prev;
            prev = slow;
            slow=nxt;
        }
        fast=head, slow=prev;

        while(slow){
            if(fast->val != slow->val)return false;
            fast=fast->next;
            slow=slow->next;
        }
        
        return true;
    }
};