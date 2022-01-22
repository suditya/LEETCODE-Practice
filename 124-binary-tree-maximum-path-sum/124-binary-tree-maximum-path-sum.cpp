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
    unordered_map<TreeNode*, int> dp;
    // int ans;
    int f(TreeNode* root,int &res)
    {
        if(root==NULL) return 0;
        // else if(root->left==NULL and root->right==NULL)
        //     return root->val;

        // else if(dp.find(root)!=dp.end())
        //     return dp[root];
        else
        {
            int l=max(0,f(root->left,res));
            int r=max(0,f(root->right,res));
            int pass_on=max(l,r)+root->val;
            int ans=max(pass_on,l+r+root->val);
            res=max(res,ans);
            return pass_on;
        }
    }
    
    int maxPathSum(TreeNode* root) 
    {
        int res=INT_MIN;
        int x=(f(root,res));
        return res;
    }
};