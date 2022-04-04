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
    ListNode* swapNodes(ListNode* head, int k) 
    {
        ListNode* firstK;
        ListNode* lastK;
        ListNode* temp=head;
        ListNode* temp1=head;
        int i=0;
        while(temp!=NULL)
        {
            ++i;
            if(i==k)
            {
                firstK=temp;
            }
            // if(i==n-k+1)
            // {
            //     lastK=temp;
            // }
            temp=temp->next;
        }
        // temp=head;
        // cout<<i<<"\n";
        int n=i;
        i=0;
        while(temp1!=NULL)
        {
            ++i;
            // if(i==k)
            // {
            //     firstK=temp;
            // }
            if(i== (n-k+1))
            {
                // cout<<"hi";
                lastK=temp1;
            }
            temp1=temp1->next;
        }
        // cout<<(firstK->val)<<" "<<(lastK->val)<<"\n";
        swap((lastK->val),(firstK->val));
        return head;
    }
};