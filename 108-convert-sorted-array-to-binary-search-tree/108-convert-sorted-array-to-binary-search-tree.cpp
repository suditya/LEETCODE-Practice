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
    TreeNode* f(vector<int>& nums, int l ,int r)
    {
        if(l>r) return NULL;
        if(l==r) 
        {
            return new TreeNode(nums[l]);
        }
        else
        {
            int mid = (l+r)/2;
            TreeNode* root=new TreeNode(nums[mid]);
            root->left=f(nums,l, mid-1);
            root->right=f(nums,mid+1, r);
            return root;
        }
        
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return NULL;
        }   
        else
        {
            int n=nums.size();
//             vector<int> l;
//             vector<int> r;
//             for(int i=0;i<n/2;i++)
//                 l.push_back(nums[i]);
//             for(int i=n/2+1;i<n;i++)
//                 r.push_back(nums[i]);
           
//             TreeNode* root= new TreeNode(nums[n/2]);
//             root->left=sortedArrayToBST(l);;
//             root->right=sortedArrayToBST(r);;
//             return root;
            return f(nums, 0, n-1);
        }
        
    }
};