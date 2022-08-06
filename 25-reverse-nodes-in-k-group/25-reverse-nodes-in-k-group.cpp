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
    ListNode* reverse(ListNode* head, ListNode* tail)
    {
        if(head==tail) return head;
        else
        {
            ListNode* reversed = reverse(head->next,tail);
            head->next->next=head;
            head->next=NULL;
            return reversed;
        }
    }
    ListNode* f(ListNode* head, int k) 
    {
        int n=1;
        ListNode* temp=head;
        while(n<k and temp!=NULL)
        {
            temp=temp->next;
            ++n;
        }
        if(temp==NULL) return head;
        // cout<<(temp->val)<<" ";
        ListNode *worked=f(temp->next,k);
        ListNode *tempy=worked;
        // cout<<"worked by recursion\n";
        // while(tempy!=NULL) { cout<<(tempy->val)<<" ";  tempy=tempy->next; }
        // cout<<"\n";
        ListNode *reversed=reverse(head,temp);
        // cout<<"reversed"<<(reversed->val)<<"\n";
        head->next=worked;
        return reversed; 
    }
    
    
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        return f(head,k);
    }
};