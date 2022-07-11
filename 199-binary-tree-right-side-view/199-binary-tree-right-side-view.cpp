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
    
    void dfs(TreeNode* root ,vector<int> &ans)
    {
        if(root==NULL) return ;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()>0)
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                TreeNode* par=q.front(); q.pop();
                if(par->left) q.push(par->left);
                if(par->right) q.push(par->right);
                
                if(i==n-1)
                {
                    ans.push_back(par->val);
                }
            }
        }
    }
    
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        dfs(root,ans);
        return ans;
    }
};