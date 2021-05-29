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
    int maxDepth(TreeNode* root) 
    {
        
        if(root==NULL)
            return 0;
        else
        {
            int left_sum=maxDepth(root->left);
            int right_sum=maxDepth(root->right);
            // return ((max(left_sum,right_sum))+1);
            int ans=max(left_sum,right_sum);
            return ans+1; 
        }
        
    }
};