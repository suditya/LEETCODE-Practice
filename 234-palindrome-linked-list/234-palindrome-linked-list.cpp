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
    ListNode* reverse(ListNode* head) 
    {
        ListNode* curr;
        ListNode* nextEle=NULL;
        ListNode* prev;
        prev=NULL, curr=head;
        while(curr!=NULL)
        {
            // cout<<(prev->val)<<" "<<(curr->val)<<" "<<(nextEle->val)<<"\n";
            nextEle=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextEle;
        }
        
        return prev;
        
    }
    
    bool isPalindrome(ListNode* head) 
    {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL and fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL)
        {
            ListNode* reversed=reverse(slow->next);
            while(reversed!=NULL)
            {
                if(reversed->val != head->val) return false;
                reversed=reversed->next;
                head=head->next;
            }
            return true;
        }
        else
        {
            ListNode* reversed=reverse(slow);
            while(reversed!=NULL)
            {
                if(reversed->val != head->val) return false;
                reversed=reversed->next;
                head=head->next;
            }
            return true;
        }
        
    }
};