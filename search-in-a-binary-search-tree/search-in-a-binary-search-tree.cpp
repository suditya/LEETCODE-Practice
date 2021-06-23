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
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if(root==NULL) return NULL;
        else
        {
            if(root->val ==val ) return root;
            else
            {
                TreeNode* l=searchBST(root->left,val);
                TreeNode* r=searchBST(root->right,val);
                if(l!=NULL) return l;
                 return r;
                // return 
            }
        }
        
    }
};