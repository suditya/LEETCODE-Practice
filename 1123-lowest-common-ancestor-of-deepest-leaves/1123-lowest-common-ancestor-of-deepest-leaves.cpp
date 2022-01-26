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
    
    pair<int,TreeNode*> f(TreeNode* root, int depth=0)
    {
        if(root==NULL) return {depth,NULL};
        // else if(root->left==NULL and root->right==NULL)
        // {
        //     return {depth,root};
        // }
        // else if(root->left==NULL or root->right==NULL)
        // {
        //     if(root->left==NULL)
        //     return {depth+1,root->right};
        //     if(root->right==NULL)
        //     return {depth+1,root->left};
        // }
        else
        {
            auto l=f(root->left,depth+1);
            auto r=f(root->right,depth+1);
            
            if(l.first > r.first)
                return l;
            else if(l.first == r.first)
            {
                l.second=root;
                return l;
            }
            else
                return r;
        }
        return {};
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        auto ans=f(root,0);
        // cout<<ans[0]<<" "<<ans[1];
        // int q=ans[1];
        return ans.second;
    }
};