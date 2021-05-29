/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) 
    {
       if(root==NULL) return {};
       else
       {
          vector<int> ans;
          int n=root->children.size();
          for(int i=0;i<n;i++)
          {
              vector<int> a=postorder(root->children[i]);
              for(int j=0;j<a.size();j++)
              {
                  ans.push_back(a[j]);
              }
          }
           ans.push_back(root->val);
          return ans;
      }
        
        
    }
};