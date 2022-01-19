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
            int ans=max(height(root->left), height(root->right));
            return ans+1;
        }
    }
    
    bool f(TreeNode* root)
    {
        if(root==NULL) return true;
        else
        {
            // if(abs(height(root->left) - height(root->right)) <= 1) return (f(root->left) and f(root->right));
            if(f(root->left) and f(root->right))
            {
                if(abs(height(root->left) - height(root->right)) <= 1) return true;
                    else return false;
            }
            else return false;
        }
    }
    
    bool isBalanced(TreeNode* root) 
    {
      return f(root);
    }
};