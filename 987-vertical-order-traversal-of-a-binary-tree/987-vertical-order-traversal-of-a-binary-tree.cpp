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
    
    map<int,multiset <pair<int,int>>>  mp;
    
    void dfs(TreeNode* root ,int depth=0,int y=0)
    {
        if(root==NULL) return ;
        else
        {
            // cout<<depth<<" "<<root->val<<" ";
            pair<int,int> p=make_pair(y,root->val);
            mp[depth].insert(p);
            if(root->left)
                dfs(root->left,depth-1,y+1);
            if(root->right)
                dfs(root->right,depth+1,y+1);
            
            return ;
        }
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        if(root==NULL) return {};
        else
        {
            vector<vector<int>> ans;
            dfs(root,0);
            for(auto x:mp)
            {
                vector<int> v;
                
                auto s=x.second;
                
                for(auto a:s)
                {
                    pair<int,int> p=a;
                    // v.push_back(a->second);
                    v.push_back(p.second);
                }
                
                // for(auto a:s->second)
                //     v.push_back(a);
                
                ans.push_back(v);
            }
            return ans;
        }
    }
};