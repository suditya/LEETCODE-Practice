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
    int goodNodes(TreeNode* root,int x=INT_MIN) 
    {
        if(root==NULL)
        return 0;
//         if(root->left==NULL and root->right==NULL)
//         {
//             if(root->val > x)
                
//         }
        else
        {
            int max=0;
            if((root->val) > x) 
                max=(root->val);
            else
                max=x;
            int l=goodNodes(root->left, max);
            int r=goodNodes(root->right, max);
            if((root->val) >= x) 
                return (l+r+1);
            else
                return (l+r);
        }
    }
};