/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    vector<int> sorted;
    unordered_map<int,Node*> mp;
    unordered_map<int,int> dontTouch;
    
    void dfs(Node* root)
    {
        if(root==NULL) return;
        else
        {
            queue<Node*> q;
            q.push(root);
            while(q.size() > 0)
            {
                int m=q.size();
                vector<Node*> v;
                for(int i=0;i<m;i++)
                {
                    Node* node=q.front();
                    q.pop();
                    v.push_back(node);
                    if(node->left !=NULL)
                    {
                        q.push(node->left);
                    }
                    if(node->right !=NULL)
                    {
                        q.push(node->right);
                    }
                }
                for(int i=0;i<m-1;i++)
                {
                    v[i]->next=v[i+1];
                }
            }
        }
    }
    
    Node* connect(Node* root) 
    {
        dfs(root);
        
        return root;
    }
};