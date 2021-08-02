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
           int x=head->val;
           delete head;
           ListNode* temp=h;
           while(temp->next!=NULL)
               temp=temp->next;
           // if(temp!=NULL)
           ListNode* last=new ListNode(x);
           temp->next=last;
           return h;
        }
        
    }
};