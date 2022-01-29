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
    
    unordered_map<int,int> mp;
    int frequent;
    
    void dfs(TreeNode* root)
    {
        if(root==NULL) return ;
        else
        {
            mp[root->val]++;
            if(mp[root->val] > frequent) frequent=mp[root->val];
            
            dfs(root->left);
            dfs(root->right);
            
        }
    }
    
    vector<int> findMode(TreeNode* root) 
    {
        vector<int> ans;
        dfs(root);
        for(auto x:mp)
        {
            if(x.second == frequent)
                ans.push_back(x.first);
        }
        return ans;
    }
};