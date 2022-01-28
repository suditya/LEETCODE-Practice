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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isSame(ListNode* head, TreeNode* root)
    {
        if(head==NULL)
            return true;
        else if(root==NULL) return false;
        else
        {
            if(head->val == root->val)
            {
                return (isSame(head->next,root->left) or isSame(head->next,root->right));
            }
            else
                return false;
        }
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        if(head==NULL) return true;
        else if(root==NULL) return false;
        else
        {
            if(head->val == root->val)
                return (isSame(head,root) or isSubPath(head,root->left) or isSubPath(head,root->right));
                else
                    return (isSubPath(head,root->left) or isSubPath(head,root->right));
        }
    }
};