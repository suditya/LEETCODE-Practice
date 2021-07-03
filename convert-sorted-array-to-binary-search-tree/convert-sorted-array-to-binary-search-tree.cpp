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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return NULL;
        }   
        else
        {
            int n=nums.size();
            vector<int> l;
            vector<int> r;
            for(int i=0;i<n/2;i++)
                l.push_back(nums[i]);
            for(int i=n/2+1;i<n;i++)
                r.push_back(nums[i]);
            TreeNode* lefty=sortedArrayToBST(l);
            TreeNode* righty=sortedArrayToBST(r);
            TreeNode* root= new TreeNode(nums[n/2]);
            root->left=lefty;
            root->right=righty;
            return root;
        }
        
    }
};