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
    
    vector<int> sorted;
    
    void dfs(TreeNode* root)
    {
        if(root==NULL) return ;
        else
        {
            dfs(root->left);
            sorted.push_back(root->val);
            dfs(root->right);
        }
    }
    
    TreeNode* makeBST(int i,int j)
    {
        if(i > j) return NULL;
        else if(i==j)
        {
            return new TreeNode(sorted[i]);
        }
        // else if(j-i == 2)
        // {
        //     TreeNode* p= new TreeNode(sorted[i+1]);
        //     TreeNode* l= new TreeNode(sorted[i]);
        //     TreeNode* r= new TreeNode(sorted[j]);
        //     p->left=l;
        //     p->right=r;
        //     return p;
        // }
        // else if(j-i ==1)
        // {
        //     TreeNode* p= new TreeNode(sorted[i+1]);
        //     TreeNode* l= new TreeNode(sorted[i]);
        //     p->left=l;
        //     return p;
        // }
        else
        {
           int mid=(i+j)/2;
            cout<<mid<<" ";
           TreeNode* parent = new TreeNode(sorted[mid]);
           parent->left= makeBST(i,mid-1);
           parent->right= makeBST(mid+1,j);
           return parent;
        }
    }
    
    TreeNode* balanceBST(TreeNode* root) 
    {
        dfs(root);
        for(auto x: sorted) cout<<x<<" ";
        cout<<"----\n";
        int n=sorted.size();
        return makeBST(0,n-1);
    }
};