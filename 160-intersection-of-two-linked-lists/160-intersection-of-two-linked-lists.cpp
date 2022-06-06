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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        unordered_map<ListNode*,int> vis;
        while(headA!=NULL)
        {
            vis[headA]++;
            headA=headA->next;
        }
        while(headB!=NULL)
        {
            if(vis[headB]>0) return headB;
            headB=headB->next;
        }
        return NULL;
    }
};