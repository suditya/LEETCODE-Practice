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
class Solution 
{
public:
    int parenty(TreeNode *root, int x)
    {
      if(root->val ==x)
          return 0;
      else
      {
          stack<TreeNode *> st;
          st.push(root);
          while(st.size()!=0)
          {
              TreeNode* parent=st.top();
              st.pop();
              if(parent->left)
              {
                  st.push(parent->left); 
                  if((parent->left->val)==x)
                      return parent->val;
              }
               if(parent->right)
              {
                  st.push(parent->right); 
                  if((parent->right->val)==x)
                      return parent->val;
              }
              // st.push(parent->left)
          }
      }
        return -1;
    }
    
    int depth(TreeNode *root,int x)
    {
        if(root==NULL) return -10;
        else if((root->val)==x)
            return 0;
        else
        {
            int m=max(depth(root->left,x), depth(root->right,x));
            return m+1;
        }
    }
    
    bool isCousins(TreeNode* root, int x, int y) 
    {
        // int a=parent(root,x);
        // int b=parent(root,y);
        // cout<<a<<" "<<b;
       if(depth(root,x)==depth(root,y))
       {
           if(parenty(root,x)!=parenty(root,y))
           return true;
           else
           return false;
       }    
       else 
           return false;
    }
};