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
    
    int f(TreeNode* root)
    {
        if(root==NULL) return 0;
        else
        {
          return f(root->left)+f(root->right)+1;
        }
    }
    
    int countNodes(TreeNode* root) 
    {
        // int count=0;
        // TreeNode* temp=root;
        // while(temp!=NULL)
        // {
        //     ++count;
        //     temp=temp->left;
        // }
        // int max_nodes = pow(2,count-1);
        return f(root);
        
    }
};