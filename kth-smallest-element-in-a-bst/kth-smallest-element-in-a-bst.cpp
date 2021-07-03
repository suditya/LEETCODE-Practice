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
    int kthSmallest(TreeNode* root, int k) 
    {
        // if(root==NULL)
        //     return INT_MAX;
        // else
        {
            vector<int> v;
            stack<TreeNode*> st;
            st.push(root);
            while(st.size()!=0)
            {
                TreeNode* p =st.top();
                st.pop();
                v.push_back(p->val);
                if(p->left)
                {
                    st.push(p->left);
                }
                if(p->right)
                {
                    st.push(p->right);
                }
                
            }
            sort(v.begin(), v.end());
            return v[k-1];
                
        }
        
    }
};