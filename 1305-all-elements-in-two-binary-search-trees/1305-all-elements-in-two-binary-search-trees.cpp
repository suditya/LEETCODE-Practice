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
    multiset<int> s;
    
    void dfs(TreeNode* root)
    {
        if(root==NULL) return ;
        else
        {
            
            dfs(root->left);
            s.insert(root->val);
            dfs(root->right);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> ans;
        dfs(root1) , dfs(root2);
        for(auto x: s)
            ans.push_back(x);
        return ans;
    }
};