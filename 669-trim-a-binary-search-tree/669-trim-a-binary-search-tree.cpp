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
    
    TreeNode* f(TreeNode* root, int l,int h)
    {
        if(root==NULL) return NULL;
        else
        {
            TreeNode* lefty=f(root->left,l,h);
            TreeNode* righty=f(root->right,l,h);
            if(root->val < l or root->val > h)
            {
                if(lefty!=NULL)
                    root=lefty;
                else
                    root=righty;
                
                
                return root;
            }
            else
            {
                root->left=lefty;
                root->right=righty;
                
                return root;
            }
        }
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) 
    {
        if(root==NULL) return root;
        else
        {
            return f(root,low,high);
        }
    }
};