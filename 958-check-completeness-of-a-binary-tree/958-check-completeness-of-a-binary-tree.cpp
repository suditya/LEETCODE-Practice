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
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*> q;
        q.push(root);
        // int p=1;
        // int count=0;
        vector<int> v;
        while(q.size()>0)
        {
            int m=q.size();
            // cout<<m<<" "<<p<<"\n";
//             if(p!=m) 
//             {
//                 ++count;
//                 if(count > 1) return false;
//             }
            
//             p=p*2;
            
            for(int i=0;i<m;i++)
            {
                
                TreeNode* node=q.front();
                if(node==NULL)
                    {v.push_back(-1); q.pop();}
                else
                {
                    v.push_back(node->val);
                    q.pop();
                    if(node->left)
                        q.push(node->left);
                    else
                        q.push(NULL);
                    if(node->right)
                        q.push(node->right);
                    else
                        q.push(NULL);
                }
            }
        }
        int flag=false;
        for(auto x:v)
        {
            if(x==-1)
                flag=true;
            if(flag==true and x>0) return false;
        }
        return true;
    }
};