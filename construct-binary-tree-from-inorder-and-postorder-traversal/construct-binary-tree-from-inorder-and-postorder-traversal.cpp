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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(inorder.size()==1)
        {
            TreeNode* root=new TreeNode(inorder[0]);
            return root;
        }
        if(inorder.size()==0 or postorder.size()==0)
        {
            return NULL;
        }
        vector<int> lp;
        vector<int> li;
        vector<int> rp;
        vector<int> ri;
        int n=inorder.size();
        int rooty=postorder[n-1];
        cout<<rooty<<"\n";
        int r=0;
        for(;inorder[r]!=rooty;r++)
        {
            li.push_back(inorder[r]);
            // cout<<li[r]<<" ";
        }
        // cout<<"\n";
        
        for(int i=0;i<r;i++)
        {
            lp.push_back(postorder[i]);
            // cout<<lp[i]<<" ";
            
        }
        // cout<<"\n";
        
        for(int i=r+1;i<n;i++)
        {
            ri.push_back(inorder[i]);
            // cout<<ri[i]<<" ";
            
        }
        // cout<<"\n";
        for(int i=r;i<n-1;i++)
        {
            rp.push_back(postorder[i]);
            // cout<<rp[i]<<" ";
        }
        
        // cout<<"\n";
        
        TreeNode* lefty=buildTree(li,lp);
        TreeNode* righty=buildTree(ri,rp);
        TreeNode* parent=new TreeNode(rooty);
        parent->left=lefty;
        parent->right=righty;
        return parent; 
        
        
    }
};