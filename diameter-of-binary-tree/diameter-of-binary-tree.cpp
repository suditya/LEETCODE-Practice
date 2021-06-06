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
    int max_depth(TreeNode* root)
    {
        if(root==NULL) return 0;
        else
        {
            int l=max_depth(root->left);
            int r=max_depth(root->right);
            return (max(l,r)+1);
        }
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if(root==NULL) return 0;
        else
        {
            int lefty=max_depth(root->left);
            int righty=max_depth(root->right); 
            // return (max(lefty,righty)+1);
            int d1=lefty+righty;
            int lr =diameterOfBinaryTree(root->left);
            int rr= diameterOfBinaryTree(root->right);
            int d2 = max(lr,rr);
            return max(d1,d2);
        }
        
    }
};