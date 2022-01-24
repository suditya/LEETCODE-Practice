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
    
    bool f(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL and root2==NULL) return true;
        else if(root1==NULL or root2==NULL)
        {
            return false;
        }
        else
        {
            if(root1->val != root2->val) return false;
            // else if(root1->left->val == root2->left->val)
            //     return ( f(root1->left,root2->left) and f(root1->right,root2->right) );
            // else if(root1->left->val == root2->right->val)
            // return ( f(root1->left,root2->right) and f(root1->right,root2->left) );
            // else
            //     return false;
            return (f(root1->left,root2->left) and f(root1->right,root2->right)  or f(root1->left,root2->right) and f(root1->right,root2->left) );
        }
    }
    
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        return f(root1,root2);        
    }
};