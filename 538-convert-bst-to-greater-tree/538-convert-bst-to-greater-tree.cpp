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
    vector<int> v;
    map<int,int> mp;
    void levelTraversal(TreeNode* root)
    {
        if(root==NULL)
        {
            return ;
        }
        else
        {
            levelTraversal(root->left);
            v.push_back(root->val);
            levelTraversal(root->right);
        }
    }
    
    void f(TreeNode* root)
    {
        if(root==NULL) return ;
        else
        {
            root->val=mp[root->val];
            f(root->left);
            f(root->right);
        }
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {
        levelTraversal(root);
        int n=v.size();
        int lSum=0,rSum=0;
        for(int i=0;i<n;i++)
        {
            rSum+=v[i];
        }
        
        for(int i=0;i<n;i++)
        {
            lSum+=v[i];
            rSum-=v[i];
            // cout<<
            mp[v[i]]=rSum+v[i];
            // cout<<v[i]<<" "<<mp[v[i]]<<"\n";
        }
        f(root);
        return root;
    }
};