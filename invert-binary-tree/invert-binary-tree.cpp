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
    void helper(TreeNode* r1,TreeNode* r2,TreeNode * root)
    {
        if((r1==NULL) and (r2==NULL)) return ;
        else if((r1==NULL) or (r2==NULL))
        {
            if(r1==NULL)
            {
                TreeNode * temp=root->right;
                root->right=NULL;
                root->left=temp;
                helper(root->left->left,root->left->right,root->left);
                return ;
            }
            else
            {
               
                TreeNode * temp=root->left;
                root->left=NULL;
                root->right=temp;
                helper(root->right->left,root->right->right,root->right);
                return ;
            }
        }
        else
        {
            swap((r1->val),(r2->val));
            // if((r1->left)!=NULL or (r2->right))
            helper(r1->left,r2->right,root);
            // else
            // {
            //     if(r1->left==NULL)
            //     {
            //         TreeNode * temp=r2->right;
            //         r2->right=NULL;
            //         r1->left=temp;
            //     }
            //     else
            //     {
            //         TreeNode * temp=r1->left;
            //         r1->left=NULL;
            //         r2->right=temp;
            //     }
            // }
            // if((r1->right)!=NULL or (r2->left))
            helper(r1->right,r2->left,root);
            // else
            // {
            //    if(r1->right==NULL)
            //     {
            //         TreeNode * temp=r2->left;
            //         r2->left=NULL;
            //         r1->right=temp;
            //     }
            //     else
            //     {
            //         TreeNode * temp=r1->right;
            //         r1->right=NULL;
            //         r2->left=temp;
            //     } 
            // }
            return ;
        }
    }
        
    TreeNode* invertTree(TreeNode* root)
    {
        if(root==NULL) return NULL;
        else
        {
        TreeNode* parent=new TreeNode(root->val);
        TreeNode* lefty=invertTree(root->right);
        TreeNode* righty=invertTree(root->left);
        parent->left=lefty;
        parent->right=righty;
        return parent;
        }
        
    }
};