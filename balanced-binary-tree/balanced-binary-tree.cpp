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
    int h(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        else
        {
            return max(h(root->left), h(root->right))+1;
        }
    }
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
            return 1;
        else
        {
            if(abs(h(root->left)-h(root->right))<=1)
                return (isBalanced(root->left) and isBalanced(root->right));
            else
                return false;
        }
        
    }
};