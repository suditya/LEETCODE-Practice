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
    vector<TreeNode*> f(int n)
    {
        if(n==1)
        {
            TreeNode* root= new TreeNode(0);
            vector<TreeNode*> v;
            v.push_back(root);
            return v;
        }
        else
        {
            vector<TreeNode*> ans;
            for(int i=1;i<=n-2;i+=2)
            {
                auto l=f(i);
                auto r=f(n-1-i);
                for(auto x:l)
                {
                    for(auto y:r)
                    {
                        TreeNode* root= new TreeNode(0);
                        root->left=x;
                        root->right=y;
                        ans.push_back(root);
                    }
                }
            }
            return ans;
        }
    }
    
    
    vector<TreeNode*> allPossibleFBT(int n) 
    {
        if(n%2==0) return {};
        else
            return f(n);
    }
};