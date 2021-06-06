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
    int sumOfLeftLeaves(TreeNode* root) 
    {
        if(root== NULL) return 0;
        // else if((root->left) ==NULL) return (root->val);
        else
        {
            int lefty=sumOfLeftLeaves(root->left);
            int righty=sumOfLeftLeaves(root->right);
            int sum=lefty+righty;
            if((root->left) and ((root->left->left==NULL) and (root->left->right==NULL)))
                return sum+(root->left->val);
            else
                return sum;
        }
        
    }
};