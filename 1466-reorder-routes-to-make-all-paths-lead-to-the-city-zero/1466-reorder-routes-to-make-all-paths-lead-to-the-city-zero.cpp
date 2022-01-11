class Solution {
public:
    int count;
    int vis[50009];
    unordered_map<int,vector<int>> mp;
    
    void dfs(int x)
    {
        if(vis[x]==1) return ;
        vis[x]=1;
        vector<int> v= mp[x];
        cout<<x;
        for(int i=0;i<v.size();i++)
        {
            // cout<<v[i]<<" ";
            if(v[i] >= 0)
            {
                if(vis[v[i]]==0)
                {
                    count=count+1;
                    dfs(v[i]);
                }
            }
            else
            {
                if(vis[-v[i]]==0)
                {
                    dfs(-v[i]);
                }
            }
        }
        return ;
    }
    
    int minReorder(int n, vector<vector<int>>& connections) 
    {
      for(int i=0;i<connections.size();i++)
      {
          mp[connections[i][0]].push_back(connections[i][1]);
          mp[connections[i][1]].push_back(-connections[i][0]);
      }
      count=0;
      memset(vis,0,sizeof(vis));
      dfs(0);
      return count;  
    }
};