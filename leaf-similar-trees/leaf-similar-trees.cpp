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
    vector<int> leaf(TreeNode * root)
    {
        if(root==NULL) return {};
        else if( (root->left ==NULL ) and (root->right== NULL))
        {
            vector<int> ans;
            ans.push_back(root->val);
            return ans;
        }
        else
        {
            vector<int> lefty=leaf(root->left);
            vector<int> righty=leaf(root->right);
            for(int i=0;i<righty.size();i++)
                lefty.push_back(righty[i]);
            return lefty;
        }
    }
        
    bool leafSimilar(TreeNode* root1, TreeNode* root2) 
    {
        vector<int> r1=leaf(root1);
        vector<int> r2=leaf(root2);
        if(r1.size()==r2.size())
        {
            for(int i=0;i<r1.size();i++)
            {
                if(r1[i]!=r2[i]) return false;
            }
            return true;
        }
        else
            return false;
    }
};