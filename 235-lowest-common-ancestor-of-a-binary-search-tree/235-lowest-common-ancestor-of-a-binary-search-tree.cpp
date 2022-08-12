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
    vector<TreeNode*> parents2(TreeNode* root,TreeNode* node)
    {
        if(root==nullptr) return {};
        else
        {
            vector<TreeNode*> ans;
            stack<TreeNode*> st;
            st.push(root);
            while(st.size()!=0)
            {
                TreeNode* p=st.top();
                st.pop();
                ans.push_back(p);
                if(p->val ==node->val) 
                {
                    break;
                }
                else if(p->val < node->val)
                {
                    if(p->right)
                    st.push(p->right);
                }
                else
                {
                    if(p->left)
                    st.push(p->left);
                }
            }
            return ans;
        }
        
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        // if(root==NULL) return  NULL; 
        // else
        {
           if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
        }
    }
};