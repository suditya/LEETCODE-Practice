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
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
        if(root==NULL)
        {
            return {};
            //base case 
        }
        else if((root->left)==NULL and (root->right)==NULL )
        {
            if(root->val == sum )
                return {{root->val}};
            else
                return {};
        }
            // return {};
        else
        {
            vector<vector<int>> ans;
            auto l=pathSum(root->left, sum-(root->val));
            auto r=pathSum(root->right, sum-(root->val));
            // return {};
            // if(l[0].size()==0 and r[0].size()==0)
            // {
            //     cout<<"a";
            //     return {};
            // }   
            for(int i=0;i<l.size();i++)
            {
                if(l[i].size()!=0)
                {
                vector<int> v=l[i];
                vector<int> x;
                x.push_back(root->val);
                for(int a=0;a<v.size();a++)
                {
                    x.push_back(v[a]);
                }
                ans.push_back(x);
                }
            }
            for(int i=0;i<r.size();i++)
            {
                if(r[i].size()!=0)
                {
                vector<int> v=r[i];
                vector<int> x;
                x.push_back(root->val);
                for(int a=0;a<v.size();a++)
                {
                    x.push_back(v[a]);
                }
                ans.push_back(x);
                }
            }
            return ans;
            
        }
    }
};