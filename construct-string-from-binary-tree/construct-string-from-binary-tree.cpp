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
    string tree2str(TreeNode* root) 
    {
        if(root==NULL) return "";
        else
        {
            string ans=to_string(root->val);
            string lefty=tree2str(root->left);
            string righty=tree2str(root->right);
            if(lefty.size()==0 and righty.size()==0 )
                return ans;
            else
            {
                // if(lefty!="()" and righty!="()")
                // return (ans+"(" +lefty+ ")" + "(" + righty+")");
                // else if(lefty=="()" and righty=="()")
                //     return ans;
                // else if(lefty=="()" or righty=="()") 
                // {
                //   if(lefty=="()")
                //       return (ans+"(" +lefty+ ")" + "(" + righty+")");
                //   else
                //       return (ans+"(" +lefty+ ")" );
                // }
                // else
                //     return "";
                if(lefty.size()==0)
                    return (ans+"(" +lefty+ ")" + "(" + righty+")");
                else if(righty.size()==0)
                    return (ans+"(" +lefty+ ")" );
                else
                    return (ans+"(" +lefty+ ")" + "(" + righty+")"); 
                    
            }
            
        }
        
    }
};