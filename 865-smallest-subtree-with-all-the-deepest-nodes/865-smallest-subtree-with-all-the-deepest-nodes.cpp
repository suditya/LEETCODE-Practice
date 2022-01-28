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
    pair<int, TreeNode*> f(TreeNode* root, int depth=0)
    {
        if(root==NULL)
        {
            return {depth-1,NULL};
        }
        else
        {
            auto l=f(root->left, depth+1);
            auto r=f(root->right, depth+1);
            if(l.first > r.first)
                return l;
            else if(l.first < r.first)
                return r;
            else
            {
                l.second=root;
                return l;
            }
        }
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
      return f(root).second;   
    }
};