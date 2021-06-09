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
    int sumEvenGrandparent(TreeNode* root) 
    {
        if(root==NULL) return 0;
        else if((root->val) %2==0)
        {
            int sum=0;
            if(root->left)
            if((root->left->left) or (root->left->right) )
            {
                if((root->left->left))
                    sum=(root->left->left->val)+sum;
                if((root->left->right))
                    sum=(root->left->right->val)+sum;
                
            }
            if(root->right)
            if((root->right->left) or (root->right->right))
            {
                if((root->right->left))
                    sum=(root->right->left->val)+sum;
                if((root->right->right))
                    sum=(root->right->right->val)+sum;
            }
            
            return sum+sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
            
            
        }
        else
        {
            return sumEvenGrandparent(root->left)+sumEvenGrandparent(root->right);
            
        }
        
    }
};