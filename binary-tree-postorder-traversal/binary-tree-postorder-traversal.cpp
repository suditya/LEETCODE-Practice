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
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        vector<int> lefty=postorderTraversal(root->left);
        vector<int> righty=postorderTraversal(root->right);
        int n=righty.size();
        for(int i=0;i<n;i++)
        {
            lefty.push_back(righty[i]);
        }
        lefty.push_back(root->val);
        return lefty;
        
        
    }
};