class Solution {
public:
    int provinces;
    int parent[205];
    // int rank[205];
    
    int find( int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i]=find( parent[i]);
    }
    void _union(int u,int v)
    {
        int pu=find(u);
        // parent[u]=pu;
        int pv=find(v);
        // parent[v]=pv;
        if(pu != pv)
        {
           
            if(pu < pv)
            {
                parent[pv]=pu;
                
            }
            else
                parent[pu]=pv;
        }
        return ;
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
        // cout<<find_parent(2);
        set<int> s;
        for(int i=0;i<n;i++)
        {
            cout<<parent[i]<<" ";
            s.insert(find(parent[i]));
        }
        return s.size();
    }
};