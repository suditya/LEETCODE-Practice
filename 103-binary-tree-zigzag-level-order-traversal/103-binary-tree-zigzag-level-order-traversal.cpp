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
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        int level=0;
        while(q.size()>0)
        {
            int m=q.size();
            vector<int> v;
            for(int i=0;i<m;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                v.push_back((node->val));
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(level%2!=0)
            {
                reverse(v.begin(),v.end());
                ans.push_back(v);
            }
            else
            {
                ans.push_back(v);
            }
            ++level;
        }
        return ans;
    }
};