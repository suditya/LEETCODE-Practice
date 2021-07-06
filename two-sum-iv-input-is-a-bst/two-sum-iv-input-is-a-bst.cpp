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
    bool findTarget(TreeNode* root, int k) 
    {
        if(root==NULL) return NULL;
        else
        {
            unordered_map<int,int> mp;
            stack<TreeNode*> st;
            st.push(root);
            while(st.size()!=0)
            {
                TreeNode * p= st.top();
                st.pop();
                mp[p->val]++;
                if(p->left)
                    st.push(p->left);
                if(p->right)
                    st.push(p->right);
                    
            }
            for(auto it = mp.begin();it!=mp.end();it++)
            {
                int x=k-(it->first);
                if(x== it->first) continue;
                if(mp.count(x)>0)
                    return true;
            }
            return false;
        }
        
    }
};