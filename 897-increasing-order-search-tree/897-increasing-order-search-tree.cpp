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
    TreeNode* increasingBST(TreeNode* root) {
        
        vector<int> ans; 
        inOrder(root,ans);
        TreeNode *parent= new TreeNode(ans[0]);
        TreeNode *temp= parent;
        for(int i=0;i<ans.size()-1;i++)
        {
            TreeNode *r = new TreeNode(ans[i+1]);
            parent->right=r;
            parent->left=NULL;
            parent=parent->right; 
            
        }
        return temp;
    }
    
    void inOrder(TreeNode *root,vector<int>& ans)
    {
        if(root==NULL)
        {
            // vector<int> v;
            // return v;
            return ;
        }
        else
        {
            inOrder(root->left,ans);
            ans.push_back(root->val);
            inOrder(root->right,ans);
            // for(int i=0;i<r.size();i++)
            // {
            //     l.push_back(r[i]);
            // }
            return ;
            
        }
    }
};