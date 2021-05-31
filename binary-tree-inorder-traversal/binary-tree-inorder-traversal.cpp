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
    vector<int> inorderTraversal(TreeNode* root) 
    {
        if(root==NULL) 
 {
    return{};
 }
 else
 {
   //  vector<int> ans;
    vector<int> l=inorderTraversal(root->left);
    l.push_back(root->val);
    vector<int> r = inorderTraversal(root->right);
    int n=r.size();
    for(int i=0;i<n;i++)
    {
       l.push_back(r[i]);
    }
    return l;

 }    
        
    }
};