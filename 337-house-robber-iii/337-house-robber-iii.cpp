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
    
    unordered_map<TreeNode*,int> dp;
    
    int f(TreeNode* root)
    {
        if(root==NULL) return 0;
        else if(dp.find(root)!=dp.end()) return dp[root];
        else
        {
            int a=root->val;
            if(root->left !=NULL)
            {
                a=a+f(root->left->left);
                a=a+f(root->left->right);
            }
            if(root->right !=NULL)
            {
                a=a+f(root->right->left);
                a=a+f(root->right->right);
            }
            return dp[root]=max(a,(f(root->left)+f(root->right)));
            
        }
    }
    
    int rob(TreeNode* root) 
    {
        return f(root);    
    }
};