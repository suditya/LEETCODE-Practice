class Solution {
public:
    int n;
    vector<int> adj[1000];
    void dfs(vector<int> adj[],vector<int> &vis,int node)
    {
        vis[node]=1;
        for(auto i:adj[node])
        {
            if(vis[i]==0)
            {
                dfs(adj,vis,i);
            }
        }
        return ;
    }
    
    void makeAdj(vector<vector<int>>& v)
    {
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(v[i][j]==1)
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        return ;
    }
    
    int findCircleNum(vector<vector<int>>& a) {
        n=a.size();
        makeAdj(a);
        vector<int> vis(n,0);
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                ++count;
                dfs(adj,vis,i);
            }
        }
        return count;
    }
};