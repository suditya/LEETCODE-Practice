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
    unordered_map<int,TreeNode*> mp;
    vector<int> sorted;
    
    void dfs(TreeNode* root)
    {
        if(root==NULL)
            return ;
        else
        {
            dfs(root->left);
            mp[root->val]=root;
            sorted.push_back(root->val);
            dfs(root->right);
        }
    }
    
    void recoverTree(TreeNode* root) 
    {
        dfs(root);
        
        int n=sorted.size();
        
        vector<int> temp=sorted;
        sort(temp.begin(),temp.end());
        
        for(int i=0;i<n;i++)
        {
           mp[sorted[i]]->val = temp[i]; 
        }
        cout<<"\n";
        
    }
};