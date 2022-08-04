/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverse(ListNode* node)
    {
        if(node==NULL) return NULL;
        else if(node->next ==NULL) return node;
        else
        {
            ListNode* temp=reverse(node->next);
            node->next->next=node;
            node->next=NULL;
            return temp;
        }
    }
    
    void deleteNode(ListNode* node) 
    {
        vector<int> ele;
        ListNode* temp=node->next;
        while(temp!=NULL)
        {
            ele.push_back(temp->val);
            // cout<<((temp->val))<<" ";
            temp=temp->next;
        }
        int n=ele.size();
        for(int i=0;i<n;i++)
        {
            // cout<<ele[i]<<" ";
            node->val=ele[i];
           
            if(i==n-1) node->next=NULL;
             node=node->next;
        }
        // node->next=NULL;
        return ;
    }
};