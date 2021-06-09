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
    int height(TreeNode * root)
    {
        if(root==NULL) return 0;
        else
        {
            return max(height(root->left), height(root->right))+1;
        }
    }
    
    vector<int> f(TreeNode * root, int h)
    {
        if(root==NULL) return {};
        else if(h==1) return {(root->val)};
        else
        {
            vector<int> lefty=f(root->left, h-1);
            vector<int> righty=f(root->right, h-1);
            for(int i=0;i<righty.size();i++)
                lefty.push_back(righty[i]);
            return lefty;
        }
    }
        
    int deepestLeavesSum(TreeNode* root) 
    {
    // { if(root==NULL) return 0;
    //   else if((root->left==NULL) and (root->right==NULL))
    //       return (root->val);
    //   else if((root->left==NULL) or (root->right==NULL))
    //   {
    //       if(root->left)
    //       {
    //           return deepestLeavesSum(root->left);
    //       }
    //       else
    //           return deepestLeavesSum(root->right);
    //   }
    //   else
    //   {
    //       int l=deepestLeavesSum(root->left);
    //       int r=deepestLeavesSum(root->right);
    //       return l+r;
    //   }
        int h=height(root);
        cout<<"h:"<<h;
        vector<int> ans=f(root, h);
        int sum=0;
        for(int i=0;i<ans.size();i++)
        {
            sum=sum+ans[i];
        }
          
        return sum;
        
    }
};