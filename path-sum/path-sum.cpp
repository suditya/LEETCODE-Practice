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
    vector<int> sum_to_leaf(TreeNode *root)
    {
        if(root==NULL) return {};
        else if(root->left==NULL and root->right==NULL)
        {
            return {(root->val)};
        }
        else
        {
            vector<int> lefty=sum_to_leaf(root->left);
            vector<int> righty=sum_to_leaf(root->right);
            int l=lefty.size(), r=righty.size();
            // if(l==r==0) 
            // {
            //     cout<<"hi";
            //     return {(root->val)};
            // }
            // else if(l==0 or r==0)
            // {
            //     if(l==0)
            //     {
            //        for(int i=0;i<r;i++)
            //             righty[i]=righty[i]+(root->val);
            //         return righty;
            //     }
            //     else
            //     {
            //        for(int i=0;i<l;i++)
            //             lefty[i]=lefty[i]+(root->val);
            //         return lefty;
            //     }
            // }
            // else
            {
                vector<int> ans;
            for(int i=0;i<l;i++)
                ans.push_back(lefty[i]+(root->val));
            // if(l==0) lefty.push_back(root->val);
            for(int i=0;i<r;i++)
                ans.push_back(righty[i]+(root->val));
            // if(r==0) righty.push_back(root->val);
            
            return ans;
            }
              
        }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) 
    {
        // return (sum(root)==targetSum);
        if(root==NULL) return false;
        vector<int> ans=sum_to_leaf(root);
        for(int i=0;i<ans.size();i++)
        cout<<ans[i]<<" ";
        for(int i=0;i<ans.size();i++)
            if(ans[i]==targetSum)
                return true;
        return false;
    }
};