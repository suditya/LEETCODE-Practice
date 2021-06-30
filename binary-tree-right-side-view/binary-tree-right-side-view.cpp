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
    vector<int> rightSideView(TreeNode* root) 
    {
        if(root==NULL) return {};
        vector<int> ans;
        ans.push_back(root->val);
        vector<int> l=rightSideView(root->left);
        vector<int> r=rightSideView(root->right);
        for(int i=0;i<r.size();i++)
        {
            ans.push_back(r[i]);
        }
        for(int i=r.size();i<l.size();i++)
        {
            ans.push_back(l[i]);
        }
        return ans;
    }
};