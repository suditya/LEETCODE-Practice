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
    int height(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        else
        {
            int left=height(root->left);
            int right=height(root->right);
            return (max(left,right)+1);
        }
    }
//     bool binary(TreeNode* root)
//     {
        
//     }
    bool isBalanced(TreeNode* root) 
    {
        if(root==NULL)
            return true;
        else
        {
            if((isBalanced(root->left )) and(isBalanced(root->right)))
            {
            int left=height(root->left);
            int right=height(root->right);
            if(((abs(left-right))> 1)) return false;
            else
               return true;
            }
            else
                return false;
        }
        
    }
};