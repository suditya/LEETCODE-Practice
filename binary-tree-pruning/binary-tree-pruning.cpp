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
    bool leaf(TreeNode *root)
    {
        if(root->left)
            return false;
        if(root->right)
            return false;
        return true;
    }
    
    TreeNode* pruneTree(TreeNode* root) 
    {
        if(root==NULL) return root;
        else
        {
            root->left=pruneTree(root->left);
            root->right=pruneTree(root->right);
            if(root->left)
            {
                if((root->left->val)==0 and leaf(root->left))
                    root->left=NULL;
            }
            if(root->right)
            {
                if((root->right->val)==0 and leaf(root->right))
                    root->right=NULL;
            }
            if(root->val==0 and root->left==NULL and root->right==NULL)
                return NULL;
            return root;
        }
       
    }
};