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
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        // if()
        if(root==NULL) return false;
        else if(root->left==NULL and root->right==NULL)
        {
            if(root->val ==targetSum)
                return true;
            else return false;
        }
        return (hasPathSum(root->left,targetSum-(root->val)) or hasPathSum(root->right,targetSum-(root->val)));
    }
};