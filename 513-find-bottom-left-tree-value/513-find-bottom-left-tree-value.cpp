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
    pair<int,int> f(TreeNode* root, int depth =0)
    {
        cout<<depth<<" ";
        if(root==NULL)
            return {-1,-1};
        else if(root->left==NULL and root->right==NULL)
        {
            return {depth, root->val};
        }
        // else if(root->left==NULL or root->right==NULL)
        // {
        //     if(root->left==NULL)
        //         return {depth+1,root->right->val};
        //     else
        //         return {depth+1,root->left->val};
        // }
        else
        {
            auto l=f(root->left, depth+1);
            auto r=f(root->right, depth+1);
            if(l.first < r.first)
                return r;
            else if(r.first < l.first)
            {
                return l;
            }
            else if(r.first == l.first)
            {
                if(r.first==-1) return {depth,root->val};
                else
                return l;
            }
            else
                return {-1,-1};
        }
    }
    
    int findBottomLeftValue(TreeNode* root) 
    {
      return f(root,0).second;   
    }
};