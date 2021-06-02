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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        if(root==NULL) return {};
        else
        {
            vector<vector<int>>  ans;
            vector<int> rooty;
            rooty.push_back(root->val);
            ans.push_back(rooty);
            vector<vector<int>> lefty=levelOrder(root->left);
            vector<vector<int>> righty=levelOrder(root->right);
            if(lefty.size() < righty.size())
            {
                int i=0;
                for(;i<lefty.size();i++)
                {
                    vector<int> x=lefty[i];
                    vector<int> y=righty[i];
                    vector<int> v;
                    	v.insert(v.begin(), x.begin(), x.end());
	v.insert(v.end(), y.begin(), y.end());
                    ans.push_back(v);
                }
                for(int j=i;j<righty.size();j++)
                {
                    ans.push_back(righty[j]);
                }
                return ans;
            }
            else
            {
                int i=0;
                for(;i<righty.size();i++)
                {
                    vector<int> x=lefty[i];
                    vector<int> y=righty[i];
                    vector<int> v;
                    	v.insert(v.begin(), x.begin(), x.end());
	v.insert(v.end(), y.begin(), y.end());
                    ans.push_back(v);
                }
                for(int j=i;j<lefty.size();j++)
                {
                    ans.push_back(lefty[j]);
                }
                return ans;
            }
            
            
                     
        }
        
    }
};