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
    bool symtry(TreeNode* root1, TreeNode* root2)
    {
        if((root1==NULL) and (root2==NULL)) return true;
        else if((root1==NULL) or (root2==NULL)) return false;
        else if((root1->val)==(root2->val))
            return (symtry((root1->left), (root2->right)) and symtry((root1->right), (root2->left)));
        else return false;
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(root==NULL) return true;
        else
        {
          if(symtry((root->left),(root->right)))
              return true;
          else return false;
              // return random(true,false);
            
        }
        
    }
};