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
    ListNode* f( ListNode* l1, ListNode* l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode*h1 = l1;
        ListNode*h2 = l2;
        if(h1->val<=h2->val){
            h1->next = f(h1->next,h2);
            return h1;
        }
        else{
            h2->next =  f(  h1,h2->next);
            return h2;
        }
        if(l1->val<=l2->val)
            return l1;
         return l2;
     }
    
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
       return f(l1,l2);
    }
    
};