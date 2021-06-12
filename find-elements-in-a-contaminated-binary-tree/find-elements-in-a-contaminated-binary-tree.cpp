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
class FindElements {
public:
    set<int> ans;
    FindElements(TreeNode* root) 
    { 
        if(root==NULL) return;
//         else if((root->val) ==-1)
//         {
//             // cout<<"A";
//             root->val=0;
//             ans.insert(0);
//             if(root->left)
//             {
//             root->left->val=1;
//             ans.insert(1);
//             }
//             if(root->right)
//             {
//             root->right->val=2;
//             ans.insert(2);
//             }
//             if(root->left)
//             FindElements(root->left);
//             if(root->right)
//             FindElements(root->right);            
//         }
//         else
//         {
//             // cout<<"B";
//             int x = root->val;
//             // cout<<x<<" ";
//             if(root->left)
//             {
//                 root->left->val=(2*x)+1;
//                 cout<<(root->left->val)<<" ";
//                 ans.insert((root->left->val));
                
//             }
//             if(root->right)
//             {
//                 root->right->val=(2*x)+2;
//                 cout<<(root->right->val)<<" ";
//                 ans.insert((root->right->val));
//             }
//             if(root->left)
//             FindElements(root->left);
//             if(root->right)
//             FindElements(root->right);
//             return ;
//         }
        stack<TreeNode *> st;
        root->val=0;
        st.push(root);
        ans.insert(0);
        while(st.size()!=0)
        {
            TreeNode *parent= st.top();
            st.pop();
            int x= parent->val;
            if(parent->left)
            {
                parent->left->val= (2*x)+1;
                ans.insert(parent->left->val);
                st.push(parent->left);
            }
            if(parent->right)
            {
                parent->right->val= (2*x)+2;
                ans.insert(parent->right->val);
                st.push(parent->right);
            }
        }
        
            
        
    }
   
    bool find(int target) 
    {
        return ans.count(target) > 0;
        
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */