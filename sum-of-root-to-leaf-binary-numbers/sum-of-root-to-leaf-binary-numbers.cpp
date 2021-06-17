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
    vector<string> leafy(TreeNode *root)
    {
        if(root == NULL) 
        {
            // vector<string> v;
            // v.push_back("");
            return {""};
        }   
        else
        {
            string rooty=to_string(root->val);
            // cout<<rooty<<" ";
            vector<string> l=leafy(root->left);
            vector<string> ans;
            vector<string> r=leafy(root->right);
            for(int i=0;i<l.size();i++)
            {
               
                // string s=l[i];
                if(l[i]!="")
                {
                string x;
                x=rooty+l[i];
                ans.push_back(x);
                }
            }
            for(int i=0;i<r.size();i++)
            {
                // string s=r[i];
                if(r[i]!="")
                {
                string x=rooty+r[i];
                ans.push_back(x);
                }
            }
            // cout<<ans.size();
            // for(int i=0;i<ans.size();i++)
            // {
            //     ans.push_back(rooty+r[i]);
            //     // cout<<ans[i]<<" ";
            // }
            // // cout<<"hi";
            if(l[0]=="" and r[0]=="")
            {
                // cout<<"q";
                return {rooty};
            }    
            
            return ans;
            
        }
    }
    
    
    int sumRootToLeaf(TreeNode* root) 
    {
        if(root==NULL) return 0;
        vector<string> ans=leafy(root);
        int sum=0;
        for(int i=0;i<ans.size();i++) 
        {
            cout<<ans[i]<<" ";
            // if(i%2==0)
            sum=sum+stoull(ans[i], 0, 2);
        }    
        // cout<<"hi";
        return sum;
        
    }
};