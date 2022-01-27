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
    pair<int,int> f(TreeNode* root)
    {
        if(root==NULL)
        {
            return {0,0};
        }
        else if(root->left==NULL and root->right==NULL) return {root->val,root->val};
        else
        {
            int mini=INT_MAX;
            int maxi=INT_MIN;
            if(root->left)
            {
                auto l=f(root->left);
                ans=max({ans,abs(root->val-l.first), abs(l.second-root->val)});
                mini=min({mini,l.first,root->val});
                maxi=max({maxi,l.second,root->val});
            }
            if(root->right)
            {
                auto r=f(root->right);
                ans=max({ans,abs(root->val-r.first), abs(r.second-root->val)});
                mini=min({mini,r.first,root->val});
                maxi=max({maxi,r.second,root->val});
            }
            
            return {mini,maxi};
        }
    }
    
    
    int maxAncestorDiff(TreeNode* root) 
    {
        ans=0;
        auto e=f(root);
        return ans;   
    }
};