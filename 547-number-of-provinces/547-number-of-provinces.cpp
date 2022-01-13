class Solution {
public:
    int provinces;
    int parent[205];
    // int rank[205];
    
    int find( int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i]=find(parent[i]);
    }
    void _union(int u,int v)
    {
        u=find(u);
        // parent[u]=pu;
        v=find(v);
        // parent[v]=pv;
        if(u != v)
        {
           
            if(u < v)
            {
                parent[v]=u;
                
            }
            else
                parent[u]=v;
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        for(int i=0;i<205;i++)
            parent[i]=i; 
        
        int n=isConnected.size();
        
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    cout<<i<<" "<<j<<"\n";
                    _union(i,j);
                }
            }
                
        }
        // cout<<find_parent(3);
        
        // set<int> s;
        int count=0;
        for(int i=0;i<n;i++)
        {
            // cout<<parent[i]<<" ";
            if(parent[i]==i)
                ++count;
            // s.insert(parent[i]);
        }
        return count;
    }
};