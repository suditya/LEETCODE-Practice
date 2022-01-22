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
    int ans;
    int f(TreeNode* root,int previous=0)
    {
        if(root==NULL) return 0;
        // else if(root->left==NULL and root->right==NULL)
        //     return root->val;

        // else if(dp.find(root)!=dp.end())
        //     return dp[root];
        else
        {
            int l=max(0,f(root->left));
            int r=max(0,f(root->right));
            // ans=max(a,b);
            // int a=max({l,r,l+r,0})+root->val;
            // int b=max(l,r);
            // // cout<<a<<" "<<b<<"\n";
            // return dp[root]=max(a,b);
            ans=max(ans,(l+r+(root->val)));
            return max({l,r})+(root->val);
        }
    }
    
    int maxPathSum(TreeNode* root) 
    {
        ans=INT_MIN;
      return (f(root),ans);   
    }
};