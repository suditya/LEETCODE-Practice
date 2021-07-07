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
    vector<TreeNode*> parents(TreeNode* root,TreeNode* node)
    {
        if(root==NULL) return{};
        
        else if( root->val == node->val )
            return {(root)};
        else
        {
            vector<TreeNode *> ans;
            ans.push_back(root);
            if(root->val < node->val)
            {
                vector<TreeNode*> r=parents(root->right,node);
                for(int i=0;i<(r.size());i++)
                {
                    ans.push_back(r[i]);
                }
                return ans;
            }
            else
            {
                vector<TreeNode*> l=parents(root->left,node);
                for(int i=0;i<(l.size());i++)
                {
                    ans.push_back(l[i]);
                }
                return ans;
            }
        }
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==NULL) return  NULL; 
        else
        {
            // vector<TreeNode*> p;
            auto a=parents(root,p);
            auto b=parents(root,q);
            if(a.size()<=b.size())
            {
                for(int i=a.size()-1;i>=0;i--)
                {
                    if(a[i]==b[i])
                        return a[i];
                }
            }
            else
            {
                for(int i=b.size()-1;i>=0;i--)
                {
                    if(a[i]==b[i])
                        return b[i];
                     // return NULL;
                    
                }
            }
                
          return NULL;  
        }
    }
};