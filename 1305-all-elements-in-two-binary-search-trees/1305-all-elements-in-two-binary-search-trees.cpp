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
    
    
    void dfs(TreeNode* root,queue<int> &s)
    {
        if(root==NULL) return ;
        else
        {
            
            dfs(root->left,s);
            s.push(root->val);
            dfs(root->right,s);
        }
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) 
    {
        queue<int> s,t;
        vector<int> ans;
        dfs(root1,s) ; dfs(root2,t);
        while( (s.size() > 0 )and t.size() > 0 )
        {
            if(s.front() < t.front())
            {
                ans.push_back(s.front());
                s.pop();
            }
            else
            {
               ans.push_back(t.front());
                t.pop(); 
            }
        }
        while(s.size() > 0)
        {
            ans.push_back(s.front());
            s.pop();
        }
        while(t.size() > 0)
        {
            ans.push_back(t.front());
            t.pop();
        }
        return ans;
    }
};