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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {

        ListNode* dummy = new ListNode(0);
        ListNode *pre=dummy, *curr;

        dummy->next=head;

        int l=1;
        while(l<left){
            pre = pre->next;
            l++;
        }
        curr=pre->next;

        for(int j=0; j<right-left; j++)
        {
            ListNode* nxt = curr->next;
            curr->next = nxt->next;
            nxt->next = pre->next;
            pre->next = nxt;
        }
        return dummy->next;
    }
};