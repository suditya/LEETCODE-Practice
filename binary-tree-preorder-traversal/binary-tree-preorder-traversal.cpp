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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        if(root==NULL)
            return {};
        vector<int> ans;
        ans.push_back(root->val);
        vector<int> lefty=preorderTraversal(root->left);
        vector<int> righty=preorderTraversal(root->right);
        int m=lefty.size();
        for(int i=0;i<m;i++)
        {
            ans.push_back(lefty[i]);
        }
        int n=righty.size();
        for(int i=0;i<n;i++)
        {
            ans.push_back(righty[i]);
        }
        // lefty.push_back(root->val);
        return ans;
        
    }
};