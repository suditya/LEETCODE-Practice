class Solution {
public:
    int vis[2005];
    int dfs[2005];
    
    bool isCycle(int node,vector<int> adj[])
    {
        vis[node]=1;
        dfs[node]=1;
        for(auto i:adj[node])
        {
            if(vis[i]==1)
            {
                if(dfs[i]==1)
                return true;
            }
            else
            {
                if(isCycle(i,adj)==true)
                    return true;
            }
        }
        dfs[node]=0;
        return false;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) 
    {
        vector<int> adj[numCourses+1];
        for(auto v:pre)
        {
            adj[v[0]].push_back(v[1]);
        }
        memset(vis,0,sizeof(vis));
        memset(dfs,0,sizeof(dfs));
        
        for(int i=0;i<numCourses;i++)
        {
            if(vis[i]==0)
            {
                if(isCycle(i,adj)==true)
                {
                    cout<<i;
                    return false;
                }
            }
        }
        return true;
    }
};