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
    int mod = 1000000007;
    
    long long ans = 0;
    
    int updateNodes(TreeNode *root){
        if(not root) return 0;
        
        int leftSum = updateNodes(root->left);
        int rightSum = updateNodes(root->right);
        
        root->val += leftSum+rightSum;
        
        return root->val;
    }
    
    void traverse(TreeNode *root, int totalSum){
        if(not root) return;
        long long temp = (long long) ((root->val)*((long long)(totalSum-root->val)));
        cout<<temp<<" : ";
        ans = max(ans,temp);
        
        traverse(root->left, totalSum);
        traverse(root->right, totalSum);
    }
    
    int maxProduct(TreeNode* root) {
        int totalSum = updateNodes(root);
        cout<<totalSum;
        traverse(root, totalSum);
        return ans%mod;
    }
    
    
};