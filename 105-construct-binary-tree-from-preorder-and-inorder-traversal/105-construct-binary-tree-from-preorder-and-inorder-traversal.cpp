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
    
    int count;
    TreeNode* f(vector<int>& p, vector<int>& in)
    {
        if(in.size()==0)
        {
            // cout<<"*\n";
            ++count;
            return NULL;
        }
        else if(in.size()==1)
        {
            TreeNode* parent=new TreeNode(in[0]);
            // cout<<in[0]<<"\n";
            // cout<<in[0]<<"\n";
            // cout<<"*\n";
            ++count;
            
            
            return parent;
        }
        else
        {
            // cout<<"*\n";
            ++count;
            int n=in.size();
            vector<int> lp,li,ri,rp;
            int root=p[0];
            int pivot =-1;
            for(int i=0;i<n;i++)
            {
                if(in[i]==root)
                {
                    pivot=i;
                    break;
                }
            }
            for(int i=0;i<n;i++)
            {
                if(i < pivot)
                {
                    li.push_back(in[i]);
                }
                if(i > pivot)
                {
                    ri.push_back(in[i]);
                }
            }
            
            for(int i=1;i<n and i<=li.size();i++)
                lp.push_back(p[i]);
            for(int i=li.size()+1;i<n;i++)
                rp.push_back(p[i]);
            
//             cout<<root<<"-->\n";
            
//             for(int i=0;i<li.size();i++)
//                 cout<<li[i]<<" ";
//             cout<<"\n";
            
//             for(int i=0;i<lp.size();i++)
//                 cout<<lp[i]<<" ";
//             cout<<"\n";
//             for(int i=0;i<ri.size();i++)
//                 cout<<ri[i]<<" ";
//             cout<<"\n";
//             for(int i=0;i<rp.size();i++)
//                 cout<<rp[i]<<" ";
//             cout<<"\n";
            
            TreeNode* parent=new TreeNode(root);
            parent->left=f(lp,li);
            parent->right=f(rp,ri);
            cout<<count<<"\n";
            return parent;
            
            return NULL;
            
        }
    }
    
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) 
    {
        count=0;
        cout<<in.size()<<"--";
        return f(pre,in);
    }
};