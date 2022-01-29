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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
        if(root==NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int x=0;
        while(q.size()>0)
        {
            int m=q.size();
            vector<int> v(m);
            for(int i=0;i<m;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                // v.push_back(node->val);
                if((x&1) !=0)
                    v[m-1-i]= (node->val);
                else
                    v[i]=(node->val);
                if(node->left !=NULL)
                    q.push(node->left);
                if(node->right!= NULL)
                    q.push(node->right);
            }
            // if((x&1) !=0) //odd
            //     reverse(v.begin(),v.end());
            ans.push_back(v);
            ++x;
        }
        
        return ans;
    }
};