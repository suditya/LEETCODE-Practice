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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        ListNode* temp=head;
        ListNode* temp2=head;
        int s=0;
        while(temp!=NULL)
        {
            temp=temp->next;
            ++s;
        }
        if(s==n)
        {
            cout<<"1";
            head=head->next;
            return head;
        }
        for(int i=1;i<(s-n);i++)
        {
            temp2=temp2->next;
        }
        cout<<(temp2->next->val)<<" ";
        if(temp2->next!=NULL)
        {
            cout<<"0";
            cout<<(temp2->next->next);
            temp2->next=temp2->next->next;
        }
        else if((temp2->next == NULL) )
        {
            return NULL;
        }
        else
            ;
        // else
        // {
        //     temp2->next=NULL;
        // }
        return head;   
        
    }
};