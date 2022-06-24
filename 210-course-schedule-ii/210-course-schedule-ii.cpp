class Solution {
public:
    vector<int> s;
    bool topo(int x, vector<int> adj[] , vector<int>& vis)
    {
        // if(vis[x]==1) return false;
        // else
        {
            vis[x]=1;
            for(auto i:adj[x])
            {
                if(vis[i]==0){
                    if( topo(i,adj,vis) == false )
                        return false;
                }
                if(vis[i]==1)
                    return false;
            }
            vis[x]=2;
            s.push_back(x);
            return true;
        }
       
         
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& p) 
    {
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(int i=0;i<p.size();i++)
        {
            vector<int> v=p[i];
            adj[v[0]].push_back(v[1]);
        }
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0){
            if(topo(i,adj,vis)==false)
                return {};
            }
        }
        
        // vector<int> ans;
        // while(s.size()!=0)
        // {
        //     ans.push_back(s.top());
        //     s.pop();
        // }
        return s;
        
    }
};