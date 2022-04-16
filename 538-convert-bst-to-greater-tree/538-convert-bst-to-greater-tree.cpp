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
    int totalSum;
    int sumAllNodes(TreeNode* root)
    {
        if(root==NULL) return 0;
        else
        {
            return (sumAllNodes(root->left)+sumAllNodes(root->right)+(root->val));
        }
    }    
    
    void levelTraversal(TreeNode* root)
    {
        if(root==NULL) return ;
        else
        {
            
            // cout<<(root->val)<<" "<<currSum<<"\n";
            levelTraversal(root->left);
            // cout<<(root->val)<<" "<<totalSum<<"\n";
            int temp=root->val;
            root->val=totalSum;
            totalSum-=temp;
            levelTraversal(root->right);
            // cout<<(root->val)<<" "<<currSum<<"\n";
        }
    }
    
    TreeNode* convertBST(TreeNode* root) 
    {
        totalSum=sumAllNodes(root);
        levelTraversal(root);
        return root;
    }
};