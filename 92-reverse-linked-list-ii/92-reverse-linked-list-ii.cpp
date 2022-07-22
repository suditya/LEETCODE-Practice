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
    vector<ListNode* > v;
    ListNode* reverseList(ListNode* head,ListNode* tail) 
    {
        if(head==tail) return head;
        else
        {
            auto revHead=reverseList(head->next,tail);
            head->next->next=head;
            head->next=NULL;
            return revHead;
        }
    }
    
    ListNode* reverseBetween(ListNode* head, int l, int r) 
    {
        ListNode* left=NULL;
        ListNode* right=NULL;
        ListNode* rightEnd=NULL;
        ListNode* leftEnd=NULL;
        ListNode* headDuplicate=head;
        int n=0;
        while(head!=NULL)
        {
            ++n;
            if(n==l-1) leftEnd=head;
            if(n==l)   left=head;
            if(n==r)   { right=head; rightEnd=head->next;  break;}
            head=head->next;
        }
        
       auto revHead=reverseList(left,right);
        
        
        // auto revHead  =v[0];
        auto revTail  =left;
        cout<<(revHead->val)<<" ";
        cout<<(revTail->val);
        if(leftEnd!=NULL)
        {
            leftEnd->next=revHead;
            revTail->next=rightEnd;
            return headDuplicate;   
        }
        else
        {
            revTail->next=rightEnd;
            return revHead;
        }
        
        
        
    }
};