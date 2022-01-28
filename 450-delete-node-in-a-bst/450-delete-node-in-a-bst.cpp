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
    
    vector<int> inorder(TreeNode* root)
    {
        if(root==NULL) return {};
        else
        {
            vector<int> l=inorder(root->left);
            l.push_back(root->val);
            vector<int> r=inorder(root->right);
            for(auto x: r)
                l.push_back(x);
            return l;
        }
    }
    
    TreeNode* makeBST(vector<int> &v,int i, int j)
    {
        if(i>j) return NULL;
        else
        {
            int mid=(i+j)/2;
            TreeNode* root=new TreeNode(v[mid]);
            root->left=makeBST(v,i,mid-1);
            root->right=makeBST(v,mid+1,j);
            return root;
        }
    }

    TreeNode* deleteNode(TreeNode* root, int key) 
    {
        if(root==NULL) return root;
        else
        {
            if(root->val == key )
            {
                vector<int> v=inorder(root->left);
                vector<int> w=inorder(root->right);
                for(auto x: w)
                    v.push_back(x);
                
                root=makeBST(v,0,v.size()-1);
                return root;
            }
            else
            {
                if(key > root->val)
                {
                    root->right = deleteNode(root->right,key);
                    return root; 
                }
                else
                {
                    root->left = deleteNode(root->left,key);
                    return root; 
                }
                    
            }
        }
    }
};