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
    
    vector<int> f(TreeNode* root)
    {
        if(root==NULL) return {};
        else
        {
            auto l=f(root->left);
            l.push_back(root->val);
            auto r=f(root->right);
            for(auto x: r)
                l.push_back(x);
            return l;
        }
    }
    
    bool findTarget(TreeNode* root, int k) 
    {
        vector<int> v=f(root); 
        int i=0;
        int j=v.size()-1;
        while(i<j)
        {
            if(v[i]+v[j]== k) return true;
            else if(v[i]+v[j] < k)
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        return false;
    }
};