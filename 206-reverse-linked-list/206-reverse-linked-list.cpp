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
    ListNode* reverseList(ListNode* head) 
    {
        if(head==NULL) return head;
        else if(head->next==nullptr)
            return head;
        else
        {
           ListNode* h=reverseList(head->next);
           head->next->next=head;
           head->next=NULL;
           return h;
        }
        
    }
};