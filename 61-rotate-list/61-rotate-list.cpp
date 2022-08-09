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
    ListNode* end;
    int size(ListNode* head)
    {
        if(head==NULL) return 0;
        if(head->next==NULL) {
            end=head;
            return 1;
        }
        else
        {
            // ListNode* slow=head;
            // ListNode* fast=head;
            // int n=0;
            // while(fast!=NULL and fast->next!=NUll)
            // {
            //     ++n;
            //     slow=slow->next;
            //     fast=fast->next->next;
            // }
            // if(fast!=NULL) return ((2*n)-1);
            // else return 2*n;
            return size(head->next)+1;
        }
    }
    ListNode* rotateRight(ListNode* head, int k) 
    {
        int n=size(head);
        if(n==0) return head;
        // cout<<n<<" size mf\n";
        k=k%n;
        if(k==0) return head;
        ListNode* temp=head;
        int i=0;
        while(temp!=NULL)
        {
            ++i;
            if(i==n-k) break;
            temp=temp->next;
        }
        ListNode* newHead=temp->next;
        temp->next=NULL;
        end->next=head;
        return newHead;
    }
};