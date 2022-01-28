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
    bool isSame(TreeNode* l , TreeNode* r)
    {
        if(l== NULL and  r==NULL) return true;
        else if(l==NULL or r==NULL) return false;
        else
        {
            if(l->val == r->val)
            {
                return (isSame(l->left,r->left) and isSame(l->right, r->right));
            }
            else
                return false;
        }
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        if(root==NULL and subRoot==NULL) return true;
        else if(root==NULL or subRoot==NULL) return false;
        else
        {
            if(root->val == subRoot->val)
                return (isSame(root,subRoot) or isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot));
            else
                return (isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot));
        }
    }
};