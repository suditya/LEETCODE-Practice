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
    int maxi(TreeNode* root)
    {
        if(root==NULL) return INT_MIN;
        if(root->left==NULL and root->right==NULL)
            return root->val;
        else
        {
            int l=maxi(root->left);
            int r=maxi(root->right);
            return max(root->val,max(l,r));
        }
    }
    int mini(TreeNode* root)
    {
        if(root==NULL) return INT_MAX;
        if(root->left ==NULL and root->right==NULL)
            return root->val;
        else
        {
            int l=mini(root->left);
            int r=mini(root->right);
            return min(root->val,min(l,r));
        }
    }
    
    bool isValidBST(TreeNode* root) 
    {
      if(root==NULL) return true;
      else
      {
          int l=maxi(root->left);
          int r=mini(root->right);
          
          if(isValidBST(root->left) and isValidBST(root->right))
          {
                if(root->left)
                {
                    if((root->val <= l))
                        return false;
                }
                if(root->right)
                {
                    if((root->val >= r))
                        return false;
                }
              return true;
                    
          }    
          return false;
              
          
      }
                  
    }
    
};