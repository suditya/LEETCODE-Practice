class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) 
    {
        vector<pair<int,int>> adj[n+1];
        int dis[n+1];
        // memset(dis, INT_MAX, sizeof(dis));
        for(int i=1;i<=n;i++) dis[i]=INT_MAX;
        bool vis[n+1];
        memset(vis,false,sizeof(vis));
        dis[k]=0;
        vis[k]=true;
        dis[0]=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>> > pq;
       
        for(int i=0;i<times.size();i++)
        {
            vector<int> v=times[i];
            
            // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<"\n";
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        pq.push({0,k});
        while(pq.size() > 0)
        {
            int distance= pq.top().first;
            int node = pq.top().second;
            
            pq.pop();
            
            for(auto i: adj[node])
            {
                int number =i.first;
                int weight =i.second;
                // cout<<node<<" "<<number<<" "<<weight<<"\n";
                if((dis[node]+weight ) < dis[number] )
                {
                    // cout<<"hey";
                    dis[number]=dis[node]+weight;
                    pq.push({dis[number],number});
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<=n;i++)
        {
            if(dis[i]==INT_MAX)
                return -1;
            ans=max(ans,dis[i]);
        }
        return ans;
        
        return 0;
    }
};