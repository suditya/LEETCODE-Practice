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
    int ans;
    
    int f(TreeNode* root)
    {
        if(root==NULL) return 0;
        else
        {
            int l= f(root->left);
            int r= f(root->right);
            ans+= abs(l-r);
            return( root->val+l+r);
        }
    }
    
    int findTilt(TreeNode* root) 
    {
        ans=0;
        int x=f(root);
        return ans;
    }
};