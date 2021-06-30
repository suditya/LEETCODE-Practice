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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) 
    {
      stack<TreeNode*> st;
      st.push(cloned);
      while(st.size()!=0)
      {
          TreeNode *p=st.top();
          st.pop();
          if(p->val ==target->val)
          {
              return p;
          }
          if(p->left)
              st.push(p->left);
          if(p->right)
              st.push(p->right);
      }
      return NULL;
    }
};