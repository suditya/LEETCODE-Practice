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
    vector<int> sorted;
    unordered_map<int,TreeNode*> mp;
    
    
    void dfs(TreeNode* root)
    {
        if(root==NULL) return ;
        else
        {
            dfs(root->left);
            sorted.push_back(root->val);
            mp[root->val]= root;
            dfs(root->right);
        }
    }
    
    TreeNode* bstToGst(TreeNode* root) 
    {
      
        dfs(root);
        int n=sorted.size();
        int sum=0;
        for(int i=n-1;i>=0;i--)
        {
            // mp[sorted[i]]+=sum;
            // sum=mp[sorted[i]];
            mp[sorted[i]]->val +=sum;
            sum= mp[sorted[i]]->val;
        }
        return root;
    }
};