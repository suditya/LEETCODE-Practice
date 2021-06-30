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
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        stack<TreeNode *> st;
        st.push(root);
        int sum=0;
        while(st.size()!=0)
        {
            TreeNode* p=st.top();
            st.pop();
            if((p->val) >=low and (p->val) <=high)
                sum=sum+(p->val);
            if(p->left)
                st.push(p->left);
            if(p->right)
                st.push(p->right);
        }
        
        return sum;
    }
};