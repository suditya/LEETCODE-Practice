/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL) return NULL;
        if(root==p or root==q) return root;
        else
        {
            auto lefty=lowestCommonAncestor(root->left,p,q);
            auto righty=lowestCommonAncestor(root->right,p,q);
            if(lefty!=NULL and righty!=NULL) return root;
            if(lefty) return lefty;
            return righty;
        }
    }
};