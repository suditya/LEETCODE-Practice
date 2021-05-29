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
    bool isUnivalTree(TreeNode* root) 
    {
        if(root==NULL) return true;
        else if(root->left==NULL and root->right==NULL)
         return true;
        else
        {
            int p=root->val;
            
            if((root->left!=NULL and root->right!=NULL))
            {
              if((p==(root->left->val)) and (p==(root->right->val)))
               return (isUnivalTree(root->left) and isUnivalTree(root->right));
              else
               return false;   
            }
            else if((root->left!=NULL and root->right==NULL))
            {
               if((p==(root->left->val)))
               return (isUnivalTree(root->left));
               else
               return false; 
            }
            else 
            {
               if((p==(root->right->val)))
               return (isUnivalTree(root->right));
               else
               return false; 
            }
           
          
               
            
           
        }
        
    }
};