/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        if(nums.size()==0)
        {
            return NULL;
        }   
        else
        {
            int n=nums.size();
            vector<int> l;
            vector<int> r;
            for(int i=0;i<n/2;i++)
                l.push_back(nums[i]);
            for(int i=n/2+1;i<n;i++)
                r.push_back(nums[i]);
           
            TreeNode* root= new TreeNode(nums[n/2]);
            root->left=sortedArrayToBST(l);;
            root->right=sortedArrayToBST(r);;
            return root;
        }
        
    }
    
    TreeNode* sortedListToBST(ListNode* head) 
    {
        vector<int> v;
        while(head!=NULL)
        {
            v.push_back(head->val);
            head=head->next;
        }
        TreeNode* root=sortedArrayToBST(v);
        return root;
    }
};