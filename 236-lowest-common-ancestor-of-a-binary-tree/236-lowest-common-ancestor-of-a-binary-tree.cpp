/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    unordered_map<TreeNode* , int> mp;
    
    bool dfs(TreeNode* root, TreeNode* target)
    {
        if(ans!=NULL)
            return false;
        if(root==NULL) return false;
        else if(root== target)
        {
            mp[target]++;
            if(mp[target]>=2)
               { ans=target; }
            return true;
        }
        else
        {
            if(dfs(root->left,target) or dfs(root->right,target) == true)
            {
                if(ans!=NULL) return false;
                mp[root]++;
                if(mp[root]>=2) 
                {
                    ans=root;\
                    // break;
                }
                return true;
            }
            else return false;
        }
        
    }
    
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        ans=NULL;
        dfs(root,p);
        dfs(root,q);
        return ans;
    }
};