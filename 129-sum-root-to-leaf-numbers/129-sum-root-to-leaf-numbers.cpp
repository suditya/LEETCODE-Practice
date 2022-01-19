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
    vector<pair<int,int>> f(TreeNode* root)
    {
        if(root==NULL)
            return {{0,0}};
        else
        {
            // auto left=f(root->left);
            // auto right=f(root->right);
            // if(root->left !=NULL)
            int number =root->val;
            vector<pair<int,int>> ans;
            if(root->left !=NULL)
            {
                auto left=f(root->left);
                for(int i=0;i<left.size();i++)
                {
                    int n=left[i].first;
                    int x=left[i].second;
                    int res=number*pow(10,x)+n;
                    cout<<res<<" ";
                    ans.push_back({res,x+1});
                }
            }
            if(root->right !=NULL)
            {
                auto right=f(root->right);
                for(int i=0;i<right.size();i++)
                {
                    int n=right[i].first;
                    int x=right[i].second;
                    int res=number*pow(10,x)+n;
                    cout<<res<<" ";
                    ans.push_back({res,x+1});
                }
            }
            if(ans.size()>=1)
            return ans;
            else
                return {{(root->val),1}};
        }
    }
    
    int sumNumbers(TreeNode* root) 
    {
        int sum=0;
        vector<pair<int,int>> v=f(root);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].first<<" ";
            sum=sum+v[i].first;  
        }
        return sum;
    }
};