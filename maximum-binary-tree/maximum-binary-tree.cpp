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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        if(nums.size()==0)
        return NULL;
        else
        {
            int max=0;
            int pos=0;
            int n=nums.size();
            for(int i=0;i<n;i++)
            {
                if(nums[i]>max) 
                {
                    max=nums[i];
                    pos=i;
                }
            }
            
            TreeNode * parent=new TreeNode (max);
            vector<int> l, r;
            for(int j=0;j<pos;j++)
                l.push_back(nums[j]);
            for(int j=pos+1;j<n;j++)
                r.push_back(nums[j]);
            TreeNode * lefty=constructMaximumBinaryTree(l);
            TreeNode * righty=constructMaximumBinaryTree(r);
            parent->left=lefty;
            parent->right=righty;
            return parent; 
        }
    }
};