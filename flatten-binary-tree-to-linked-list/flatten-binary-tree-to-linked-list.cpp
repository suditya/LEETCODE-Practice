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
    void flatten(TreeNode* root) 
    {
        if(root==NULL) return ;
        else if(root->left==NULL and root->right==NULL)
            return;
        else
        {
            flatten(root->left);
            flatten(root->right);
            if(root->left==NULL)
                return ;
            TreeNode* temp=root->left;
            TreeNode* s=root->left;
            while((temp->right)!=NULL)
            {
                temp=temp->right;
            }
            temp->right=root->right;
            root->right=s;
            root->left=NULL;
            return ;
            
        }
        
    }
};