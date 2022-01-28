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
    
    unordered_map<int,int> freq;
    int highest_freq;
    
    int sum(TreeNode* root)
    {
        if(root==NULL) return 0;
        else
        {
            int lSum=sum(root->left);
            int rSum=sum(root->right);
            int currSum=lSum+rSum+(root->val);
            freq[currSum]++;
            highest_freq=max(highest_freq,freq[currSum]);
            return currSum;
        }
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) 
    {
        highest_freq=0;
        int totalSum=sum(root);
        vector<int> ans;
        for(auto i=freq.begin();i!=freq.end();i++)
        {
            if(i->second == highest_freq)  //if the frequency of num is highest frequency
            {
                // for(int j=0;j<highest_freq;j++)
                {
                    ans.push_back(i->first);
                }
            }
        }
        
        return ans;
    }
};